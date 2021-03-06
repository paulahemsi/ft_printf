/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:26:47 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/06 09:13:03 by phemsi-a         ###   ########.fr       */
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
	int	left_align;
	int	zero_padding;
	int	min_width;
	int	precision;	
}				flags;

int	ft_printf(const char *str, ...);

#endif