/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 21:16:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/10 23:02:40 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	find_length(char *str, char *pointer)
{
	int	length;

	length = 0;
	while (str[length] != pointer[0])
		length++;
	return (length);
}

static int	ft_printf_recursive(char *str, va_list args, size_t length)
{
	char	*percent_pointer;
	char	*str_aux;

	if (!(percent_pointer = ft_strchr(str, '%')))
	{
		length += ft_strlen(str);
		ft_putstr(str);
		return (length);
	}
	if (!(str_aux = ft_substr(str, 0, find_length(str, percent_pointer))))
		return (ERROR);
	ft_putstr(str_aux);
	length += ft_strlen(str_aux);
	free(str_aux);
	length = flags_parser(&percent_pointer, args, length);
	return (ft_printf_recursive(percent_pointer, args, length));
}

int			ft_printf(const char *str, ...)
{
	va_list	args;
	int		return_num;

	va_start(args, str);
	return_num = ft_printf_recursive((char *)str, args, 0);
	va_end(args);
	return (return_num);
}

int main(void)
{
	// int i;
	// int *ptr;
	// int **ptr2;

	// i = -33;
	// ptr = &i;
	// ptr2 = &ptr;
	// int hex = 0x2a;
	ft_putnbr(ft_printf("%06u|\n%-5d|\n%05.3i|\n", -121, 42, 42));
	return (0);
}