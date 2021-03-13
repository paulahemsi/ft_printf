/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:26:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/12 23:53:04 by phemsi-a         ###   ########.fr       */
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
	// int hex = 0x2a;
	ft_putnbr(ft_printf("\n|%c|\n|%.s|\n|%04d|\n|%-5.0i|\naqui:\n|%-5.u|\n|%x|\n|%.10x|\n|%-05%|\n", 'x', "hello", 0, 43, 0, -6667, 0));
	ft_putchar('\n');
	ft_putnbr(printf("\n|%c|\n|%.s|\n|%04d|\n|%-5.0i|\naqui:\n|%-5.u|\n|%010x|\n|%x|\n|%-05%|\n", 'x', "hello" , 0, 43, 0, -6667, 0));	
	ft_putchar('\n');
	return (0);
}
