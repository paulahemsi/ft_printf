/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:11:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/13 19:14:46 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	identifier_parser(flags *flag, va_list args)
{
	if ((*flag->ptr == 'c') || (*flag->ptr == '%'))
		print_char(flag, args);
	else if (*flag->ptr == 's')
		print_string(flag, args);
	else if (*flag->ptr == 'd' || *flag->ptr == 'i' || *flag->ptr == 'u')
		print_integer(flag, args);
	else if (*flag->ptr == 'p')
		print_pointer(flag, args);
	else if (*flag->ptr == 'x' || *flag->ptr == 'X')
		print_hex(flag, args);
}

static void	update_width(flags *flag, va_list args)
{
	if (*flag->ptr == '*')
	{
		flag->min_width = va_arg(args, int);
		if (flag->min_width < 0)
		{
			flag->left_align = TRUE;
			flag->min_width *= -1;
		}
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
		while (ft_isdigit(*flag->ptr))
		{
			flag->precision = ft_atoi(flag->ptr);
			flag->ptr += ft_numlen(flag->precision);
		}
	}
	else
		flag->precision = 0;
	if ((flag->precision >= 0) && (*flag->ptr != '%'))
		flag->zero_padding = FALSE;
}

size_t		flags_parser(char **ptr, va_list args, size_t length)
{
	flags	flag;

	ft_memset(&flag, 0, sizeof(flag));
	flag.precision = -1;
	flag.length = length;
	flag.ptr = *ptr + 1;
	while (ft_strchr("-0", *flag.ptr))
		update_padding(&flag);
	if (ft_isdigit(*flag.ptr) || *flag.ptr == '*')
		update_width(&flag, args);
	if (*flag.ptr == '.')
		update_precision(&flag, args);
	if ((ft_isalpha(*flag.ptr)) || *flag.ptr == '%')
		identifier_parser(&flag, args);
	flag.ptr++;
	*ptr = flag.ptr;
	return (flag.length);
}
