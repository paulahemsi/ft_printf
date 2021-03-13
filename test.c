/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:26:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/13 14:04:17 by phemsi-a         ###   ########.fr       */
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
	ft_printf("{%.*d}", 0, 42);
	ft_putchar('\n');
	printf("{%.*d}", 0, 42);
	ft_putchar('\n');
	return (0);
}
