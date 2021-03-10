/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:49:08 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/09 18:33:18 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	print_string(flags *flag, va_list args)
{
	char	*string;
	int		length;

	if (flag->precision)
		string = ft_substr(va_arg(args, char *), 0, flag->precision);
	else
		string = ft_strdup(va_arg(args, char *));
	length = ft_strlen(string);
	if (flag->left_align)
		ft_putstr(string);
	while (flag->min_width > length)
	{
		ft_putchar(' ');
		flag->length++;
		flag->min_width--;
	}
	if (!(flag->left_align))
		ft_putstr(string);
	flag->length += ft_strlen(string);
	free(string);
}