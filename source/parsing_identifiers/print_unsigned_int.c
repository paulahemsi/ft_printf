/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:52:22 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/12 23:59:28 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb / 10 < 1)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
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

static void	print_width(flags *flag, int num_len)
{
	char	c;
	int		limit;

	if ((flag->zero_padding) && (flag->precision < 0) && !(flag->left_align))
		c = '0';
	else
		c = ' ';
	if (flag->precision > num_len)
		limit = flag->precision;
	else if (flag->precision != 0)
		limit = num_len;
	else
		limit = 0;
	while (flag->min_width > limit)
	{
		ft_putchar(c);
		flag->length++;
		flag->min_width--;
	}
}

void		print_unsigned_int(flags *flag, va_list args)
{
	unsigned int		number;
	int					num_len;

	number = va_arg(args, unsigned int);
	num_len = ft_countdigit(number);
	if (flag->left_align)
	{
		print_precision(flag, (flag->precision - num_len));
		if (flag->precision != 0)
			ft_putnbr_unsigned(number);
		print_width(flag, num_len);
	}
	else
	{
		print_width(flag, num_len);
		print_precision(flag, (flag->precision - num_len));
		if (flag->precision != 0)
			ft_putnbr_unsigned(number);
	}
	flag->length += num_len;
}
