/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:11:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/07 21:09:02 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	identifier_parser(flags *flag, va_list args)
{
	if (*flag->pointer == 'c')
		print_char(flag, args);
}

int			ft_count_number(int number)
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

size_t		flags_parser(char **pointer, va_list args, size_t length)
{
	flags	flag;

	ft_memset(&flag, 0, sizeof(flag));
	flag.length = length;
	flag.pointer = *pointer;
	flag.pointer++;
	if (*flag.pointer == '%')
	{
		ft_putchar('%');
		flag.length++;
		flag.pointer++;
	}
	else
	{
		while (ft_strchr("-0", *flag.pointer))
		{
			if (*flag.pointer == '-')
				flag.left_align = TRUE;
			if (*flag.pointer == '0')
				flag.zero_padding = TRUE;
			flag.pointer++;
		}
		if (ft_isdigit(*flag.pointer))
		{
			flag.min_width = ft_atoi(flag.pointer);
			flag.pointer += ft_count_number(flag.min_width);
		}
		if (*flag.pointer == '.')
		{
			flag.precision = TRUE;
			flag.pointer++;
			if (*flag.pointer == '*')
			{
				flag.star_precision = TRUE;
				flag.pointer++;
			}
			else if (ft_isdigit(*flag.pointer))
			{
				flag.precision = ft_atoi(flag.pointer);
				flag.pointer += ft_count_number(flag.precision);
			}
		}
		if (ft_isalpha(*flag.pointer))
			identifier_parser(&flag, args);
		flag.pointer++;
	}
	*pointer = flag.pointer;
	return (flag.length);
}
