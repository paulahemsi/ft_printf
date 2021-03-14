/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:49:08 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/14 10:08:39 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	print_s(t_flags *flag, char **string)
{
	int		length;

	length = ft_strlen(*string);
	if ((flag->left_align) && (flag->precision != 0))
		ft_putstr(*string);
	while (flag->min_width > length)
	{
		ft_putchar(' ');
		flag->length++;
		flag->min_width--;
	}
	if (!(flag->left_align) && (flag->precision != 0))
		ft_putstr(*string);
	flag->length += length;
}

void		print_string(t_flags *flag, va_list args)
{
	char	*string;

	if (flag->precision > -1)
		string = ft_substr(va_arg(args, char *), 0, flag->precision);
	else
		string = ft_strdup(va_arg(args, char *));
	if (string == NULL)
	{
		free(string);
		if (flag->precision < 0)
			flag->precision = 6;
		string = ft_substr("(null)", 0, flag->precision);
	}
	print_s(flag, &string);
	free(string);
}
