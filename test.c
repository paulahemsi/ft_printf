/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:26:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/12 13:54:40 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int i;
	int *ptr;
	int **ptr2;

	i = -33;
	ptr = &i;
	ptr2 = &ptr;
	int hex = 0x2a;
	ft_putnbr(ft_printf("\n|%c|\n|%5s|\n|%04d|\n|%-5.3i|\n|%-.4u|\n|%010x|\n|%10.5X|\n|%%|\n|%5%|\n|%.5%|\n|%-10.7%|\n", 'x', "sono", hex, -hex, 42, 6667, 6667));
	ft_putchar('\n');
	ft_putnbr(printf("\n|%c|\n|%5s|\n|%04d|\n|%-5.3i|\n|%-.4u|\n|%010x|\n|%10.5X|\n|%%|\n|%5%|\n|%.5%|\n|%-10.7%|\n", 'x', "sono", hex, -hex, 42, 6667, 6667));	
	ft_putchar('\n');
	return (0);
}
