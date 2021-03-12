/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:55:43 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/12 11:59:38 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	print_precision(flags *flag, int precision)
{
	while (precision > 0)
	{
		ft_putchar('0');
		flag->length++;
		precision--;
	}
}

static void	print_width(flags *flag, int hex_len)
{
	char	c;
	int		limit;

	if ((flag->zero_padding) && !(flag->precision) && !(flag->left_align))
		c = '0';
	else
		c = ' ';
	if (flag->precision > hex_len)
		limit = flag->precision;
	else
		limit = hex_len;
	while (flag->min_width > limit)
	{
		ft_putchar(c);
		flag->length++;
		flag->min_width--;
	}
}

void	print_pointer(flags *flag, va_list args)
{
	char				*pointer;
	int					pointer_length;

	pointer = ft_itoa_hex((va_arg(args, unsigned long int)), 'x');
	pointer_length = ft_strlen(pointer);
	if (!(flag->left_align))
		print_width(flag, pointer_length);
	print_precision(flag, (flag->precision - pointer_length));
	ft_putstr(pointer);
	if (flag->left_align)
		print_width(flag, pointer_length);
	free(pointer);
	flag->length += pointer_length;
}
