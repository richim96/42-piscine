/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:39:45 by rmei              #+#    #+#             */
/*   Updated: 2024/02/10 19:50:19 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guard_unistd.h"

void	ft_matrix_2d_print(char *matrix_2d)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			write(1, &matrix[i][j], 1);
			write(1, &matrix[i][j], 1);
			j++;
		}
		i++;
	}
}
