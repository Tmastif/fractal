/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:47:38 by ilazar            #+#    #+#             */
/*   Updated: 2024/04/26 17:14:06 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//original memcpy 

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr_src;
	unsigned int		i;

	if (dest == 0 && src == 0)
		return (NULL);
	ptr = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr[i] = ptr_src[i];
		i++;
	}
	return (ptr);
}
