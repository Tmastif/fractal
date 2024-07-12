/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:29 by ilazar            #+#    #+#             */
/*   Updated: 2024/04/22 13:13:16 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	c = (char)c;
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s != '\0')
	{
		if (*s == c)
			result = (char *)s;
		s++;
	}
	return (result);
}
