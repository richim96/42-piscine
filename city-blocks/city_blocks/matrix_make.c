/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:13:19 by nboer             #+#    #+#             */
/*   Updated: 2024/02/10 19:44:05 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guard_lib.h"

char	**ft_matrix_2d_init(int grid_size)
{
	char	**matrix_2d;
	int		i;
	int		j;

	matrix_2d = (char **) malloc(sizeof(char *) * grid_size);
	i = 0;
	while (i < grid_size)
	{
		matrix_2d[i] = (char *) malloc(sizeof(char) * (grid_size + 1));
		j = 0;
		while (j < grid_size)
		{
			matrix_2d[i][j] = j + '1';
			j++;
		}
		matrix_2d[i][j] = '\0';
		i++;
	}
	return (matrix_2d);
}
