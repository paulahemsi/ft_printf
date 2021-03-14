/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:34:03 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/13 20:10:22 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"
#include <stdio.h>

static void	print_precision(flags *flag, int precision)
{
	while (precision > 0)
	{
		ft_putchar('0');
		flag->length++;
		precision--;
	}
}

static void	print_width(flags *flag, int hex_len, char *hex)
{
	char	c;
	int		limit;

	if ((flag->zero_padding) && (flag->precision < 0) && !(flag->left_align))
		c = '0';
	else
		c = ' ';
	if (flag->precision > hex_len)
		limit = flag->precision;
	else if ((flag->precision) || (*hex != '0'))
		limit = hex_len;
	else
		limit = 0;
	while (flag->min_width > limit)
	{
		ft_putchar(c);
		flag->length++;
		flag->min_width--;
	}
}

void		print_hex(flags *flag, va_list args)
{
	char	*hex;
	int		hex_len;

	hex = ft_itoa_hex(va_arg(args, unsigned int), *flag->ptr);
	hex_len = ft_strlen(hex);
	if (!(flag->left_align))
		print_width(flag, hex_len, hex);
	print_precision(flag, (flag->precision - hex_len));
	if (*hex != '0' || flag->precision != 0)
		ft_putstr(hex);
	if (flag->left_align)
		print_width(flag, hex_len, hex);
	free(hex);
	if (*hex != '0' || flag->precision != 0)
		flag->length += hex_len;
}
