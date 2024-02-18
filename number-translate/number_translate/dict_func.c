/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:31:20 by rmei              #+#    #+#             */
/*   Updated: 2024/02/18 18:37:03 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Counts the lines in a file for allocating the correct memory size */
int	ft_lines_count(char *file_str)
{
	int	i;
	int	lines;

	if (!*file_str)
		return (0);
	i = 0;
	lines = 0;
	while (file_str[i])
	{
		if (file_str[i] == '\n' && file_str[i + 1] != '\n')
			lines++;
		i++;
	}
	return (lines);
}

char	*ft_newline_pointer_shift(char *str)
{
	while (*str != '\n')
		str++;
	while (*str == '\n')
		str++;
	return (str);
}

/* Takes the number digit on the line correspoding to the current index */
char	*ft_take_num(char *file_str, int idx)
{
	int		i;
	char	*str_temp;
	char	*num_str;

	str_temp = file_str;
	while (idx > 0)
	{
		str_temp = ft_newline_pointer_shift(str_temp);
		idx--;
	}
	i = 0;	
	while (str_temp[i] >= '0' && str_temp[i] <= '9')
		i++;
	num_str = (char *) malloc(sizeof(char) * i);
	if (!num_str)
		return (NULL);
	i = 0;
	while (str_temp[i] >= '0' && str_temp[i] <= '9')
	{
		num_str[i] = str_temp[i];
		i++;
	}
	return (num_str);
}

/* Takes the number word on the line corresponding to the current index */
char	*ft_take_word(char *file_str, int idx)
{
	int		i;
	char	*str_temp;
	char	*num_word;

	str_temp = file_str;
	while (idx > 0)
	{
		str_temp = ft_newline_pointer_shift(str_temp);
		idx--;
	}
	while (*str_temp != ':')
		str_temp++;
	while (*str_temp == ':' || *str_temp == ' ')
		str_temp++;
	i = 0;
	while (str_temp[i] != '\n')
		i++;
	num_word = (char *) malloc(sizeof(char) * i);
	if (!num_word)
		return (NULL);
	i = 0;
	while (str_temp[i] != '\n')
	{
		if (str_temp[i] == ' ' && str_temp[i + 1] == ' ')
			i++;
		else
		{
			num_word[i] = str_temp[i];
			i++;
		}
	}
	return (num_word);
}
