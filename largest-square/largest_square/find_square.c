/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:15:09 by rmei              #+#    #+#             */
/*   Updated: 2024/02/20 22:28:54 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	ft_tables_init(int rows, int cols)
{
	g_map = (char **) malloc(sizeof(char *) * rows);
	g_dt = (int **) malloc(sizeof(int *) * rows);
	if (!g_map || !g_dt)
		return ;
	g_i = 0;
	while (g_i < rows)
	{
		g_map[g_i] = (char *) malloc(sizeof(char) * cols);
		g_dt[g_i] = (int *) malloc(sizeof(int) * cols);
		if (!g_map[g_i] || !g_dt[g_i])
		{
			while (g_i--)
			{
				free(g_map[g_i]);
				free(g_dt[g_i]);
			}
			free(g_map);
			free(g_dt);
			return ;
		}
		g_i++;
	}
}

void	ft_g_map_fill(char input_map[9][27], int rows, int cols)
{
	g_i = 0;
	while (g_i < rows)
	{
		g_j = 0;
		while (g_j < cols)
		{
			g_map[g_i][g_j] = input_map[g_i][g_j];
			g_j++;
		}
		g_i++;
	}
}

void	ft_g_dt_fill(char block)
{
	if (g_i == 0 || g_j == 0)
	{
		if (g_map[g_i][g_j] == block)
			g_dt[g_i][g_j] = 0;
		else
			g_dt[g_i][g_j] = 1;
	}
	else if (g_map[g_i][g_j] == block)
		g_dt[g_i][g_j] = 0;
	else
	{
		g_dt[g_i][g_j] = ft_min(
				g_dt[g_i - 1][g_j],
				g_dt[g_i][g_j - 1],
				g_dt[g_i - 1][g_j - 1]
				) + 1;
	}
}

void	ft_find_square(int rows, int cols, char block)
{
	int	max_size;

	max_size = 0;
	g_i = 0;
	while (g_i < rows)
	{
		g_j = 0;
		while (g_j < cols)
		{
			ft_g_dt_fill(block);
			if (g_dt[g_i][g_j] > max_size)
			{
				max_size = g_dt[g_i][g_j];
				g_coord[0] = g_i - max_size + 1;
				g_coord[1] = g_j - max_size + 1;
			}
			g_j++;
		}
		g_i++;
	}
	if (max_size == 0)
		printf("No valid square found\n");
	else
	{
		printf("Largest top-left: (%d, %d)\n", g_coord[0], g_coord[1]);
		printf("Size: %d\n", max_size);
	}
}
