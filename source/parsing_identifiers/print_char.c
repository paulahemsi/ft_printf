/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:18:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/12 19:03:38 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	print_left_align(flags *flag, va_list args)
{
	if (*flag->ptr == '%')
		ft_putchar(*flag->ptr);
	else
		ft_putchar((char)va_arg(args, int));
	flag->length++;
}

static void	print_right_align(flags *flag, va_list args)
{
	if (*flag->ptr == '%')
		ft_putchar(*flag->ptr);
	else
		ft_putchar((char)va_arg(args, int));
	flag->length++;
}

void	print_char(flags *flag, va_list args)
{
	char c;

	if ((flag->zero_padding) && (*flag->ptr == '%'))
		c = '0';
	else
		c = ' ';
	if (flag->left_align)
		print_left_align(flag, args);
	while (flag->min_width > 1)
	{
		ft_putchar(c);
		flag->length++;
		flag->min_width--;
	}
	if (!(flag->left_align))
		print_right_align(flag, args);
}
