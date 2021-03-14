/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:52:50 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/13 19:49:02 by phemsi-a         ###   ########.fr       */
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

static void	print_width(flags *flag, int num_len, char sign, int number)
{
	int		s;
	char	c;
	int		limit;

	s = 0;
	if (sign)
		s = 1;
	if ((flag->zero_padding) && (flag->precision < 0) && !(flag->left_align))
		c = '0';
	else
		c = ' ';
	if ((flag->precision + s) > (num_len + s))
		limit = flag->precision + s;
	else if ((flag->precision) || (number))
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
	if (flag->zero_padding && (flag->precision != 0))
	{
		print_sign(flag, sign);
		print_width(flag, num_len, sign, number);
	}
	else
	{
		print_width(flag, num_len, sign, number);
		print_sign(flag, sign);
	}
	print_precision(flag, (flag->precision - num_len));
	if (number || (flag->precision != 0))
		ft_putnbr_unsigned(number);
}

void		print_integer(flags *flag, va_list args)
{
	char			sign;
	long int		number;
	int				num_len;

	sign = '\0';
	if (*flag->ptr == 'd' || *flag->ptr == 'i')
	{
		if ((number = va_arg(args, int)) < 0)
		{
			sign = '-';
			number *= -1;
		}
	}
	else
		number = va_arg(args, unsigned int);
	num_len = ft_countdigit((unsigned int)number);
	if (flag->left_align)
	{
		print_sign(flag, sign);
		print_precision(flag, (flag->precision - num_len));
		if (number || (flag->precision != 0))
			ft_putnbr_unsigned(number);
		print_width(flag, num_len, sign, number);
	}
	else
		print_rigth_align(flag, num_len, sign, number);
	if (number || (flag->precision != 0))
		flag->length += ft_countdigit((unsigned int)number);
}
