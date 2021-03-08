/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:11:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/08 15:25:01 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	identifier_parser(flags *flag, va_list args)
{
	if (*flag->pointer == 'c')
		print_char(flag, args);
	if (*flag->pointer == 's')
		print_string(flag, args);
}

static void	update_width(flags *flag, va_list args)
{
	if (*flag->pointer == '*')
	{
		flag->min_width = va_arg(args, int);
		flag->pointer++;
	}
	else
	{
		flag->min_width = ft_atoi(flag->pointer);
		flag->pointer += ft_numlen(flag->min_width);
	}
}

static void	update_padding(flags *flag)
{
	if (*flag->pointer == '-')
		flag->left_align = TRUE;
	if (*flag->pointer == '0')
		flag->zero_padding = TRUE;
	flag->pointer++;
}

static void	update_precision(flags *flag, va_list args)
{
	flag->pointer++;
	if (*flag->pointer == '*')
	{
		flag->precision = va_arg(args, int);
		flag->pointer++;
	}
	else if (ft_isdigit(*flag->pointer))
	{
		flag->precision = ft_atoi(flag->pointer);
		flag->pointer += ft_numlen(flag->precision);
	}
}

size_t		flags_parser(char **pointer, va_list args, size_t length)
{
	flags	flag;

	ft_memset(&flag, 0, sizeof(flag));
	flag.length = length;
	flag.pointer = *pointer + 1;
	if (*flag.pointer == '%')
	{
		ft_putchar('%');
		flag.length++;
		flag.pointer++;
	}
	else
	{
		while (ft_strchr("-0", *flag.pointer))
			update_padding(&flag);
		if (ft_isdigit(*flag.pointer) || *flag.pointer == '*')
			update_width(&flag, args);
		if (*flag.pointer == '.')
			update_precision(&flag, args);
		if (ft_isalpha(*flag.pointer))
			identifier_parser(&flag, args);
		flag.pointer++;
	}
	*pointer = flag.pointer;
	return (flag.length);
}
