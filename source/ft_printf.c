/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 21:16:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/06 13:01:38 by phemsi-a         ###   ########.fr       */
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

static char	*flags_parser(char **pointer, va_list args)
{
	char	*parsed_str;
	char	*initial_ptr;
	int		i;

	i = 0;
	initial_ptr = *pointer;
	initial_ptr++;
	parsed_str = ft_strdup("");
	if (*initial_ptr == 'i')
	{
		free(parsed_str);
		parsed_str = ft_itoa(va_arg(args, int));
		initial_ptr++;
	}
	else if (*initial_ptr == '%')
	{
		free(parsed_str);
		parsed_str = ft_strdup("%");
		initial_ptr++;
	}
	*pointer = initial_ptr;
	ft_putstr("PONTEIRO: ");
	ft_putchar(**pointer);
	ft_putchar('\n');
	return (parsed_str);
}

static void	ft_printf_recursive(char *str, va_list args)
{
	int				length;
	char			*pointer;
	char			*str_temp;
	static char		*str_return;

	if (str_return == NULL)
		str_return = ft_strdup("");
	if (!(pointer = ft_strchr(str, '%')))
	{
		str_temp = ft_strjoin(str_return, str);
		free(str_return);
		str_return = str_temp;
		ft_putstr(str_return);
	}
	else
	{
		length = find_length(str, pointer);
		str_temp = ft_strjoin(str_return, ft_substr(str, 0, length)); //!lidar com NULL
		free(str_return);
		str_return = str_temp;
		ft_putstr("JOIN COM PARTES ANTES DA %: ");
		ft_putstr(str_return);
		ft_putchar('\n');
		str_temp =ft_strjoin(str_return, flags_parser(&pointer, args)); //!lidar com NULL e leak do parser
		free (str_return);
		str_return = str_temp;
		ft_putstr("em processo: ");
		ft_putstr(str_return);
		ft_putchar('\n');
		ft_printf_recursive(pointer, args);
	}
}

int			ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	ft_printf_recursive((char *)str,args);
	va_end(args);
	return (0);
}

int main(void)
{
	ft_printf("uma string com uma porcentagem %% e um número(42) %i", 42);
}