/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:26:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/16 08:51:02 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	/*
	** 	char:
	*/
	 ft_printf("ft_printf: |%c|\n", 'x');
	 printf("___printf: |%c|\n", 'x');
	 ft_printf("ft_printf: |%3c|\n", 'x');
	 printf("___printf: |%3c|\n", 'x');
	
	/*
	** 	string:
	*/
	
	 ft_printf("ft_printf: |%2.s|\n", "42");
	 printf("___printf: |%2.s|\n", "42");
	 ft_printf("ft_printf: |%s|\n", "nariz");
	 printf("___printf: |%s|\n", "nariz");
	 ft_printf("ft_printf: |%3.7s|%7.7s|\n", "hello", "world");
	 printf("___printf: |%3.7s|%7.7s|\n", "hello", "world");
	 ft_printf("ft_printf: |%-10s|\n", "uepa");
	 printf("___printf: |%-10s|\n", "uepa");
	 ft_printf("ft_printf: |%7.7s|%4.3s|\n", "hello", "world");
	 printf("___printf: |%7.7s|%4.3s|\n", "hello", "world");
	 ft_printf("ft_printf: |%23s|\n", NULL);
	 printf("___printf: |%23s|\n", NULL);
	 ft_printf("ft_printf: |%.*s|\n", -5, "42");
	 printf("___printf: |%.*s|\n", -5, "42");
	 ft_printf("ft_printf:  --- Return : %d\n",  ft_printf("|%-2s|\n|%.s|\n|%-4s|\n|%-2.4s|\n|%-8.12s|\n|%3s|\n|%8s|\n|%---2s|\n|%.*s|\n|%.0s|\n|%.1s|\n|%.2s|\n|%.4s|\n|%.8s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	 printf("___printf:  --- Return : %d\n", printf("|%-2s|\n|%.s|\n|%-4s|\n|%-2.4s|\n|%-8.12s|\n|%3s|\n|%8s|\n|%---2s|\n|%.*s|\n|%.0s|\n|%.1s|\n|%.2s|\n|%.4s|\n|%.8s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));

	/*
	** 	integers:
	*/

	 ft_printf("ft_printf: |%3.0d|\n", 10);
	 printf("___printf: |%3.0d|\n", 10);
	 ft_printf("ft_printf:  --- Return : %d\n",  ft_printf("(null)"));
	 printf("___printf:  --- Return : %d\n", printf("(null)"));
	 ft_printf("ft_printf:  --- Return : %d\n",  ft_printf(""));
	 printf("___printf:  --- Return : %d\n", printf(""));
	 ft_printf("ft_printf: |%05.*d|\n", -15, 42);
	 printf("___printf: |%05.*d|\n", -15, 42);
	 
	 ft_printf("ft_printf: |%8.3i|\n", 8375);
	 printf("___printf: |%8.3i|\n", 8375);
	 ft_printf("ft_printf: |%4i|\n", -14);
	 printf("___printf: |%4i|\n", -14);
	 ft_printf("ft_printf: |%5.i|\n", 0);
	 printf("___printf: |%5.i|\n", 0);
	 ft_printf("ft_printf: |%010.5i|\n", -216);
	 printf("___printf: |%010.5i|\n", -216);
	 
	 ft_printf("ft_printf: |%.0u|\n", 10);
	 printf("___printf: |%.0u|\n", 10);
	 
	/*
	** 	hex:
	*/ 
	
	 ft_printf("ft_printf: |%.0x|\n", 100);
	 printf("___printf: |%.0x|\n", 100);
	 ft_printf("ft_printf: |%.x|\n", 0);
	 printf("___printf: |%.x|\n", 0);
	 ft_printf("ft_printf: |%*.*x| |%*.*X|\n", 1, 50, 5000, 1, 0, 10);
	 printf("___printf: |%*.*x| |%*.*X|\n", 1, 50, 5000, 1, 0, 10);

	/*
	** 	pointer:
	*/

	 ft_printf("ft_printf: |%1.p|\n", NULL);
	 printf("___printf: |0x|\n");
	 ft_printf("ft_printf: |%5.p|\n", NULL);
	 printf("___printf: |   0x|\n", NULL);
	
	 ft_printf("ft_printf: |%026.51%|\n");
	 printf("___printf: |0000000000000000000000000%%|\n");

	
	/*
	** 	undefined behavior:
	*/
	
	 ft_printf("ft_printf: |%09s|\n", "lala la");
	printf("__printf:|%09s|\n", "lala la");
	 ft_printf("ft_printf: |%-09s|\n", "lala la");
	printf("__printf:|%-09s|\n", "lala la");
	 ft_printf("ft_printf|:%2.9p|\n", 1234);
	printf("__printf:|%2.9p|\n", 1234);
	 ft_printf("ft_printf:|%*-c|\n", 3, 'x');
	printf("__printf:|%*-c|\n", 3, 'x');
	 ft_printf("ft_printf: |%-*c|\n", 3, 'x');
	printf("__printf:|%-*c|\n", 3, 'x');
	return (0);
}
