/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:18:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/12 14:12:57 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	print_char(flags *flag, va_list args)
{
	if (flag->left_align)
	{
		if (*flag->ptr == '%')
			ft_putchar(*flag->ptr);
		else
			ft_putchar((char)va_arg(args, int));
		flag->length++;
	}
	while (flag->min_width > 1)
	{
		ft_putchar(' ');
		flag->length++;
		flag->min_width--;
	}
	if (!(flag->left_align))
	{	
		if (*flag->ptr == '%')
			ft_putchar(*flag->ptr);
		else
			ft_putchar((char)va_arg(args, int));
		flag->length++;
	}
}
