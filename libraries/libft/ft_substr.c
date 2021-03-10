/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:36:13 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/02/15 16:43:09 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_string;

	new_string = (char *)malloc((len + 1) * sizeof(char));
	if (!s || (new_string == NULL))
	{
		return (NULL);
	}
	i = 0;
	while ((i < len) && ((start + i) < ft_strlen(s)) && (s[start + i] != '\0'))
	{
		new_string[i] = s[start + i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
