/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:07:00 by ilazar            #+#    #+#             */
/*   Updated: 2024/05/01 18:24:33 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!*s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*

void addOne(unsigned int i, char *c)
{
	*c = *c + i;
}


#include <stdio.h>
char	itoalpha(unsigned int i, char c)
{
	printf("%d %c\n", i , c);
	return ('x');
}


int	main(int ac, char **av)
{
	(void) ac;

	ft_striteri(av[1], addOne);
	printf("%s\n", av[1]);
	return 0;
}*/
