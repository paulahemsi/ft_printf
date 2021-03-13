/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:26:47 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/13 18:14:37 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libraries/libft/libft.h"
# include <stdarg.h>

# define TRUE	1
# define FALSE	0

typedef	struct	ft_printf
{
	char		*ptr;
	int			length;
	int			left_align;
	int			zero_padding;
	int			min_width;
	int			precision;	
}				flags;

int		ft_printf(const char *str, ...);
size_t	flags_parser(char **ptr, va_list args, size_t length);
void	print_char(flags *flag, va_list args);
void	print_string(flags *flag, va_list args);
void	print_ptr(flags *flag, va_list args);
void	print_integer(flags *flag, va_list args);
void	print_unsigned_int(flags *flag, va_list args);
void	print_pointer(flags *flag, va_list args);
void	print_hex(flags *flag, va_list args);

#endif
