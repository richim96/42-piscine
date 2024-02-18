/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:56:10 by rmei              #+#    #+#             */
/*   Updated: 2024/02/18 14:48:21 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FOR TESTING 
// Main function as comments at the bottom. 
// Compile with: cc args_check.c ft_putnbr.c ft_putstr.c ft_atoi.c rush-02.h -Werror -Wall -Wextra

#include "rush-02.h"

// Checks if the numeric string has only digits.
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
	ft_putstr("Error\n");
	ft_putstr(">>>> ft_is_args_valid - FAIL - String is not numeric.\n"); 			/* REMOVE THIS */
}

// Uses atoi to check if number is greater than 0.
int	ft_check_is_number_positive(char *number)
{
	int	nbr;

	nbr = ft_atoi(number);
	ft_putstr(">>>> ft_putnbr(nbr): ");
	ft_putnbr(nbr);
	ft_putstr("\n");

	if (ft_atoi(number) < 0)
	{
		ft_putstr("Error\n");		
		ft_putstr(">>>> ft_is_args_valid - FAIL - Number is negative\n"); 			/* REMOVE THIS */
		return (0);
	}
	ft_putstr(">>>> ft_is_args_valid - Number greater than 0.\n");		/* REMOVE THIS LINE*/
	return (1);
}

// Checks if file opens sucessfully.
int	ft_check_file_opens(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Dict Error\n");
		ft_putstr(">>>> ft_is_args_valid - FAIL - Error opening file.\n");      		/* REMOVE THIS LINE*/
		return (0);
	}
	ft_putstr(">>>> ft_is_args_valid - File opened successfully.\n");		/* REMOVE THIS LINE*/
	close(fd);
	return (1);
}

// Checks if command line arguments are valid. 
// It takes argc and argv as parameters, as well as
// pointers to strings that represent the name
// of the dictionary and the number input as string.
int	ft_is_args_valid(int argc, char *argv[], char **dict, char **num)
{
	if (argc == 2)
	{
		*num = argv[1];
	}
	else if (argc == 3)
	{
		*dict = argv[1];
		*num = argv[2];
	}
	else
	{
		ft_putstr("Error\n");		
		ft_putstr(">>>> ft_is_args_valid - FAIL - Wrong number of arguments\n"); 			/* REMOVE THIS */
		return (0);
	}

	if (ft_str_is_numeric(*num))
		if (ft_check_is_number_positive(*num))
			if (ft_check_file_opens(*dict))
				return (1);
	return (0);
}





/*
int	main(int argc, char *argv[])
{
	char	*string_dict;
	char	*clean_nb_input;

	string_dict = "numbers.dict";

	if (ft_is_args_valid(argc, argv, &string_dict, &clean_nb_input) != 0)
	{
		ft_putstr(string_dict);
		ft_putstr(clean_nb_input);
	}
}
*/