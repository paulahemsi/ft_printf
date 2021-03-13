/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:49:08 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/13 19:01:54 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	print_string(flags *flag, va_list args)
{
	char	*string;
	int		length;

	if (flag->precision > -1)
		string = ft_substr(va_arg(args, char *), 0, flag->precision);
	else
		string = ft_strdup(va_arg(args, char *));
	if (string == NULL)
	{
		free(string);
		string = ft_substr("(null)", 0, flag->precision);
	}
	length = ft_strlen(string);
	if ((flag->left_align) && (flag->precision != 0))
		ft_putstr(string);
	while (flag->min_width > length)
	{
		ft_putchar(' ');
		flag->length++;
		flag->min_width--;
	}
	if (!(flag->left_align) && (flag->precision != 0))
		ft_putstr(string);
	flag->length += ft_strlen(string);
	free(string);
}