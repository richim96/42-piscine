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

void	ft_write_malloc_error(void)
{
	char	*malloc_fail_msg;

	malloc_fail_msg = "Malloc failure on matrix initialization\n";
	write(2, malloc_fail_msg, sizeof(malloc_fail_msg) - 1);
}

void	ft_free_matrices_on_fail(char **matrix_2d, int i)
{
	while (i-- > 0)
		free(matrix_2d[i]);
	free(matrix_2d);
	ft_write_malloc_error();
}

void	ft_matrix_1d_fill(char **matrix_2d, int i, int grid_size)
{
	int	j;

	j = 0;
	while (j < grid_size)
	{
		matrix_2d[i][j] = '0';
		j++;
	}
	matrix_2d[i][j] = '\0';
}

char	**ft_matrix_2d_init(int grid_size)
{
	char	**matrix_2d;
	int		i;

	matrix_2d = (char **) malloc(sizeof(char *) * grid_size);
	if (!matrix_2d)
	{
		ft_write_malloc_error();
		return (NULL);
	}
	i = 0;
	while (matrix_2d && i < grid_size)
	{
		matrix_2d[i] = (char *) malloc(sizeof(char) * (grid_size + 1));
		if (!matrix_2d[i])
			ft_free_matrices_on_fail(matrix_2d, i);
		ft_matrix_1d_fill(matrix_2d, i, grid_size);
		i++;
	}
	return (matrix_2d);
}
