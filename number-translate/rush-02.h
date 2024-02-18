/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:39:36 by eduribei          #+#    #+#             */
/*   Updated: 2024/02/18 14:41:10 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h> /*REMOVE THIS?*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_is_args_valid(int argc, char *argv[], char **dic, char **num);

void		ft_putnbr(int nb);
void		ft_putstr(char *str);
int		ft_atoi(char *str);
