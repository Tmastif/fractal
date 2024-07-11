/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:35:32 by ilazar            #+#    #+#             */
/*   Updated: 2024/04/29 18:08:11 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim(const char *s1, unsigned int start, unsigned int trim_len);

char	*ft_strtrim(const char *s1, const char *set)
{
	int				right;
	unsigned int	left;
	unsigned int	trim_len;

	right = ft_strlen(s1) - 1;
	left = 0;
	while (s1[left] && ft_strchr(set, s1[left]) != NULL)
		left++;
	while (right >= 0 && s1[right] && ft_strchr(set, s1[right]) != NULL)
		right--;
	if (right < 0)
		return (ft_strdup(""));
	trim_len = right - left + 1;
	return (trim(s1, left, trim_len));
}

static char	*trim(const char *s1, unsigned int start, unsigned int trim_len)
{
	char			*trimmed;
	unsigned int	i;

	trimmed = (char *) malloc(sizeof(char) * (trim_len + 1));
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	while (i < trim_len)
	{
		trimmed[i] = s1[start];
		start++;
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
