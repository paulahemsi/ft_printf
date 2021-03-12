/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:11:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/11 22:09:20 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	identifier_parser(flags *flag, va_list args)
{
	if (*flag->ptr == 'c')
		print_char(flag, args);
	else if (*flag->ptr == 's')
		print_string(flag, args);
	else if (*flag->ptr == 'd' || *flag->ptr == 'i')
		print_integer(flag, args);
	else if (*flag->ptr == 'u')
		print_unsigned_int(flag, args);
	else if (*flag->ptr == 'p')
		print_pointer(flag, args);
	// else if (*flag->ptr == 'x' || *flag->ptr == 'X')
	// 	print_hex(flag, args);
}

static void	update_width(flags *flag, va_list args)
{
	if (*flag->ptr == '*')
	{
		flag->min_width = va_arg(args, int);
		flag->ptr++;
	}
	else
	{
		flag->min_width = ft_atoi(flag->ptr);
		flag->ptr += ft_numlen(flag->min_width);
	}
}

static void	update_padding(flags *flag)
{
	if (*flag->ptr == '-')
		flag->left_align = TRUE;
	if (*flag->ptr == '0')
		flag->zero_padding = TRUE;
	flag->ptr++;
}

static void	update_precision(flags *flag, va_list args)
{
	flag->ptr++;
	if (*flag->ptr == '*')
	{
		flag->precision = va_arg(args, int);
		flag->ptr++;
	}
	else if (ft_isdigit(*flag->ptr))
	{
		flag->precision = ft_atoi(flag->ptr);
		flag->ptr += ft_numlen(flag->precision);
	}
}

size_t		flags_parser(char **ptr, va_list args, size_t length)
{
	flags	flag;

	ft_memset(&flag, 0, sizeof(flag));
	flag.length = length;
	flag.ptr = *ptr + 1;
	if (*flag.ptr == '%')
	{
		ft_putchar('%');
		flag.length++;
		flag.ptr++;
	}
	else
	{
		while (ft_strchr("-0", *flag.ptr))
			update_padding(&flag);
		if (ft_isdigit(*flag.ptr) || *flag.ptr == '*')
			update_width(&flag, args);
		if (*flag.ptr == '.')
			update_precision(&flag, args);
		if (ft_isalpha(*flag.ptr))
			identifier_parser(&flag, args);
		flag.ptr++;
	}
	*ptr = flag.ptr;
	return (flag.length);
}
