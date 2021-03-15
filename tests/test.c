/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:26:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/15 12:03:43 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_printf("|%c|\n", 'x');
	printf("|%c|\n", 'x');
	ft_printf("|%3c|\n", 'x');
	printf("|%3c|\n", 'x');
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
	ft_printf(" --- Return : %d\n", ft_printf("|%-2s|\n|%.s|\n|%-4s|\n|%-2.4s|\n|%-8.12s|\n|%3s|\n|%8s|\n|%---2s|\n|%.*s|\n|%.0s|\n|%.1s|\n|%.2s|\n|%.4s|\n|%.8s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	printf(" --- Return : %d\n", printf("|%-2s|\n|%.s|\n|%-4s|\n|%-2.4s|\n|%-8.12s|\n|%3s|\n|%8s|\n|%---2s|\n|%.*s|\n|%.0s|\n|%.1s|\n|%.2s|\n|%.4s|\n|%.8s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	ft_printf(" --- Return : %d\n", ft_printf("(null)"));
	printf(" --- Return : %d\n", printf("(null)"));
	ft_printf(" --- Return : %d\n", ft_printf(""));
	printf(" --- Return : %d\n", printf(""));
	ft_printf("|%09s|\n", "lala la");
	printf("|%09s|\n", "lala la");
	ft_printf("|%-09s|\n", "lala la");
	printf("|%-09s|\n", "lala la");
	ft_printf("|%2.9p|\n", 1234);
	printf("|%2.9p|\n", 1234);
	int n = 10;
	int *ptr = &n;
	ft_printf("|%2.9p|\n", ptr);
	printf("|%2.9p|\n", ptr);
	return (0);
}
