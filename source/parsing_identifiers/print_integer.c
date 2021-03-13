/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:52:50 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/13 12:23:41 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	print_sign(flags *flag, char sign)
{
	if (sign)
	{
		ft_putchar(sign);
		flag->length++;
	}
}

static void	print_precision(flags *flag, int precision)
{
	while (precision > 0)
	{
		ft_putchar('0');
		flag->length++;
		precision--;
	}
}

static void	print_width(flags *flag, int num_len, char sign)
{
	int		s;
	char	c;
	int		limit;

	s = 0;
	if (sign)
		s = 1;
	if ((flag->zero_padding) && (flag->precision == -1) && !(flag->left_align))
		c = '0';
	else
		c = ' ';
	if ((flag->precision + s) > (num_len + s))
		limit = flag->precision + s;
	else if (flag->precision != 0)
		limit = num_len + s;
	else
		limit = 0;
	while (flag->min_width > limit)
	{
		ft_putchar(c);
		flag->length++;
		flag->min_width--;
	}
}

static void	print_rigth_align(flags *flag, int num_len, char sign, int number)
{
	if (flag->zero_padding && (flag->precision <= 0))
	{
		print_sign(flag, sign);
		print_width(flag, num_len, sign);
	}
	else
	{
		print_width(flag, num_len, sign);
		print_sign(flag, sign);
	}
	print_precision(flag, (flag->precision - num_len));
	if (flag->precision != 0)
		ft_putnbr(number);
}

void		print_integer(flags *flag, va_list args)
{
	char	sign;
	int		number;
	int		num_len;

	sign = '\0';
	if ((number = va_arg(args, int)) < 0)
	{
		sign = '-';
		number *= -1;
	}
	num_len = ft_countdigit((unsigned int)number);
	if (flag->left_align)
	{
		print_sign(flag, sign);
		print_precision(flag, (flag->precision - num_len));
		if ((flag->precision != 0))
			ft_putnbr(number);
		print_width(flag, num_len, sign);
	}
	else
		print_rigth_align(flag, num_len, sign, number);
	flag->length += ft_countdigit((unsigned int)number);
}
