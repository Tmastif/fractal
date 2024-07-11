/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:56:43 by ilazar            #+#    #+#             */
/*   Updated: 2024/04/26 18:17:44 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	ptr_dest = (unsigned char *) dest;
	ptr_src = (const unsigned char *) src;
	i = 0;
	if (!ptr_dest && !ptr_src)
		return (NULL);
	if (ptr_dest > ptr_src)
	{
		while (n-- > 0)
		{
			ptr_dest[n] = ptr_src[n];
		}
	}
	else
	{
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return (ptr_dest);
}
