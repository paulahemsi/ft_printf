/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 09:50:17 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/12 10:34:35 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_hex(unsigned int number, char case_conversion_char)
{
	char	*hex;
	int		convert_to_hex;
	int		length;
	int		case_conversion;

	length = ft_countdigit(number);
	hex = (char *)malloc((length + 1) * sizeof(char));
	if (!hex)
		return (NULL);
	hex[length] = '\0';
	if (case_conversion_char == 'X')
		case_conversion = 55;
	else
		case_conversion = 87;
	while (number > 0)
	{
		length--;
		convert_to_hex = number % 16;
		if (convert_to_hex < 10)
			hex[length] = convert_to_hex + 48;
		else
			hex[length] = convert_to_hex + case_conversion;
		number /= 16;
	}
	return (hex);
}
