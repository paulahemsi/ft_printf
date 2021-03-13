/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 09:50:17 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/13 09:49:52 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_hex(unsigned long int number, char case_conversion_char)
{
	char	*hex;
	int		convert_to_hex;
	int		length;
	int		case_conversion;
	char	temp;

	length = ft_countdigit(number);
	if (!(hex = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	if (case_conversion_char == 'X')
		case_conversion = 55;
	else
		case_conversion = 87;
	if (number == 0)
	{
		hex[0] = '0';
		hex[1] = '\0';
		return(hex);
	}
	length = 0;
	while (number > 0)
	{
		convert_to_hex = number % 16;
		if (convert_to_hex < 10)
			hex[length] = convert_to_hex + 48;
		else
			hex[length] = convert_to_hex + case_conversion;
		number /= 16;
		length++;
	}
	hex[length] = '\0';
	case_conversion = ft_strlen(hex);
	length = 0;
	while (length < (case_conversion/2))
    {
        temp = hex[length];
        hex[length] = hex[case_conversion - length - 1];
        hex[case_conversion - length - 1] = temp;
        length++;
    }
	return (hex);
}
