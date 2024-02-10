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

#include <stdio.h>
#include <stdlib.h>

/* Malloc to create reusable arrays */
int	*ft_matrix_init(void);

int	*ft_matrix_2d_init(void)
{
	int	matrix_1[5];
	int	matrix_2[5];
	int	matrix_3[5];
	int	matrix_4[5];
	int	matrix_2d[5];

	matrix_1 = {0, 0, 0, 0, '\0'};
	matrix_2 = {0, 0, 0, 0, '\0'};
	matrix_3 = {0, 0, 0, 0, '\0'};
	matrix_4 = {0, 0, 0, 0, '\0'};
	matrix_2d = {matrix_1, matrix_2, matrix_3, matrix_4, '\0'};
	return (matrix_2d);
}
