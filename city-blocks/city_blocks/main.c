/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:49:47 by rmei              #+#    #+#             */
/*   Updated: 2024/02/10 19:29:38 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guard_lib.h"

int		ft_is_not_format(char *str, int g);
char	**ft_matrix_2d_init(int grid_size);
void	ft_matrix_2d_print(char **matrix_2d, int grid_size);

/* main() ensures input correctness before calling the solving function */
int	main(int argc, char **argv)
{
	char	*matrix_1d;
	char	**matrix_2d;
	char	*error_msg;
	int		grid_size;

	grid_size = 4;
	error_msg = "Error\n";
	if (argc != 2)
	{
		write(2, error_msg, sizeof(error_msg) - 1);
		return (-1);
	}
	matrix_1d = argv[1];
	if (ft_is_not_format(matrix_1d, grid_size))
	{
		write(2, error_msg, sizeof(error_msg) - 1);
		return (-1);
	}
	matrix_2d = ft_matrix_2d_init(grid_size);
	ft_matrix_2d_print(matrix_2d, grid_size);
	return (0);
}
