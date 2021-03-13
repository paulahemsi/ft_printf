/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:26:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/13 16:23:55 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i;
	int *ptr;
	int **ptr2;

	i = -33;
	ptr = &i;
	ptr2 = &ptr;
	// int hex = 0x2a;
	ft_printf("|%3.0d|\n", 10);
	printf("|%3.0d|\n", 10);
	ft_putchar('\n');
	ft_printf("|%8.3i|\n", 8375);
	printf("|%8.3i|\n", 8375);
	ft_putchar('\n');
	ft_printf("|%4i|\n", -14);
	printf("|%4i|\n", -14);
	ft_putchar('\n');
	ft_printf("|%5.i|\n", 0);
	printf("|%5.i|\n", 0);
	ft_putchar('\n');
	ft_printf("|%.0u|\n", 10);
	printf("|%.0u|\n", 10);
	ft_putchar('\n');
	ft_printf("|%.0x|\n", 100);
	printf("|%.0x|\n", 100);
	ft_putchar('\n');
	ft_printf("|%.x|\n", 0);
	printf("|%.x|\n", 0);
	ft_putchar('\n');
	ft_printf("|%*.*x| |%*.*X|\n", 1, 50, 5000, 1, 0, 10);
	printf("|%*.*x| |%*.*X|\n", 1, 50, 5000, 1, 0, 10);
	ft_putchar('\n');
	ft_printf("|%1.p|\n", NULL);
	printf("|0x|\n");
	ft_putchar('\n');
	ft_printf("|%5.p|\n", NULL);
	printf("|   0x|\n", NULL);
	return (0);
}
