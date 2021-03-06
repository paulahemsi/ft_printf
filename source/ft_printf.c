/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 21:16:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/06 13:49:18 by phemsi-a         ###   ########.fr       */
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

static int update_str(char **str_return, char **str_temp, char **str_aux)
{
	free(*str_return);
	free(*str_aux);
	if (*str_temp == NULL)
		return (ERROR);
	*str_return = *str_temp;
	return (0);
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
	return (parsed_str);
}

static int	ft_printf_recursive(char *str, va_list args)
{
	int				length;
	char			*pointer;
	char			*str_temp;
	char			*str_aux;
	static char		*str_return;

	if (str_return == NULL)
		str_return = ft_strdup("");
	if (!(pointer = ft_strchr(str, '%')))
	{
		str_temp = ft_strjoin(str_return, str);
		free(str_return);
		str_return = str_temp;
		ft_putstr(str_return);
		free(str_return);
		return (1);
	}
	else
	{
		length = find_length(str, pointer);
		if (!(str_aux = ft_substr(str, 0, length)))
			return (ERROR);
		str_temp = ft_strjoin(str_return, str_aux);
		if (update_str(&str_return, &str_temp, &str_aux) == ERROR)
			return (ERROR);
		if (!(str_aux = flags_parser(&pointer, args)))
			return (ERROR);
		str_temp =ft_strjoin(str_return, str_aux);
		if (update_str(&str_return, &str_temp, &str_aux) == ERROR)
			return (ERROR);
		return (ft_printf_recursive(pointer, args));
	}
}

int			ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	if (ft_printf_recursive((char *)str,args) == ERROR)
		return (ERROR);
	va_end(args);
	return (0);
}

int main(void)
{
	ft_printf("uma string com uma porcentagem %% e um número(42) %i e outro número (dessa vez 1048) %i e vamos mais um(1234567) %i", 42, 1048, 1234567);
}