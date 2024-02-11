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

#include "guard_lib.h"

void	ft_matrix_2d_print(char **matrix_2d, int grid_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid_size)
	{
		j = 0;
		while (j < grid_size)
		{
			write(1, &matrix_2d[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		free(matrix_2d[i]);
		i++;
	}
	free(matrix_2d);
}
