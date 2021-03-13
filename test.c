/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:26:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/13 19:08:32 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
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
	ft_printf("|%2.s|\n", "42");
	printf("|%2.s|\n", "42");
	ft_printf("|%s|\n", "nariz");
	printf("|%s|\n", "nariz");
	ft_printf("|%3.7s|%7.7s|\n", "hello", "world");
	printf("|%3.7s|%7.7s|\n", "hello", "world");
	ft_printf("|%-10s|\n", "nark nark");
	printf("|%-10s|\n", "nark nark");
	ft_printf("|%7.7s|%4.3s|\n", "hello", "world");
	printf("|%7.7s|%4.3s|\n", "hello", "world");
	ft_printf("|%23s|\n", NULL);
	printf("|%23s|\n", NULL);
	ft_printf("|%010.5i|\n", -216);
	printf("|%010.5i|\n", -216);
	ft_printf("|%05.*d|\n", -15, 42);
	printf("|%05.*d|\n", -15, 42);
	ft_printf("|%.*s|\n", -5, "42");
	printf("|%.*s|\n", -5, "42");
	ft_printf("|%026.51%|\n");
	printf("|0000000000000000000000000%%|\n");
	
	// printf("COMEÇO|%-70.193x|%-140c|%168c|%026.51%|%0125.119X|\n" ,1102840003u,-50,-17,3721437512u);
	return (0);
}
