/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:11:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/07 16:45:54 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_count_number(int number)
{
	size_t digits;

	digits = 0;
	if (number == 0)
		return (1);
	else if (number < 0)
	{
		digits ++;
		number *= -1;
	}
	while (number >= 1)
	{
		number /= 10;
		digits++;
	}
	return (digits);
}

size_t	flags_parser(char **pointer, va_list args, size_t length)
{
	char	*initial_ptr;
	int		number;

	initial_ptr = *pointer;
	initial_ptr++;
	if (*initial_ptr == 'i')
	{
		number = va_arg(args, int);
		ft_putnbr(number);
		length += ft_count_number(number);
			// ft_putchar('\n');
			// ft_putstr("length += contar numero: ");
			// ft_putnbr(length);
			// ft_putchar('\n');
		initial_ptr++;
	}
	else if (*initial_ptr == '%')
	{
		ft_putchar('%');
		length++;
			// ft_putchar('\n');
			// ft_putstr("length += acrescentar %: ");
			// ft_putnbr(length);
			// ft_putchar('\n');
		initial_ptr++;
	}
	*pointer = initial_ptr;
	return (length);
	
}
