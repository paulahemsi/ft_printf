/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:26:47 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/15 11:47:53 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libraries/libft/libft.h"
# include <stdarg.h>

# define TRUE		1
# define FALSE		0
# define POINTER	'p'

typedef	struct	s_ft_printf
{
	char		*ptr;
	int			length;
	int			left_align;
	int			zero_padding;
	int			min_width;
	int			precision;
}				t_flags;

int				ft_printf(const char *str, ...);
size_t			flags_parser(char **ptr, va_list args, size_t length);
void			print_char(t_flags *flag, va_list args);
int				print_string(t_flags *flag, va_list args);
void			print_integer(t_flags *flag, va_list args);
int				print_hex(t_flags *flag, va_list args);

#endif
