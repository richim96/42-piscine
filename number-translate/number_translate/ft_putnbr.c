/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:04:17 by eduribei          #+#    #+#             */
/*   Updated: 2024/02/18 10:59:17 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

void	print_zero(void)
{
	char	zero;

	zero = '0';
	write(1, &zero, 1);
}

void	print_minimun(void)
{
	char	*min;
	int		index;

	min = "-2147483648";
	index = 0;
	while (min[index] != '\0')
	{
		write(1, &min[index], 1);
		index++;
	}
}

void	print(int index, char p[])
{
	index--;
	while (index >= 0)
	{
		write(1, &p[index], 1);
		index--;
	}
}

void	ft_putnbr(int nb)
{
	char	c[12];
	int		digit;
	int		index;

	index = 0;
	if (nb == 0)
		print_zero();
	else if (nb == -2147483648)
		print_minimun();
	else
	{
		if (nb < 0) 
		{
			nb = -nb;
			write(1, "-", 1);
		}
		while (nb > 0)
		{
			digit = nb % 10;
			c[index] = digit + '0';
			nb = nb / 10;
			index++;
		}
		print(index, c);
	}
}
