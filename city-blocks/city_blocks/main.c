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

#include "guard_unistd.h"

int	ft_is_not_format(char *str, int g);

/* main() ensures input correctness before calling the solving function */
int	main(int argc, char **argv)
{
	char	*matrix_1d;
	int		grid_size;

	grid_size = 4;
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (-1); 
	}
	matrix_1d = argv[1];
	if (ft_is_not_format(matrix_1d, grid_size))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	// ft_matrix_write(matrix_1d);
	write(1, "Success\n", 8);
	return (0);
}
