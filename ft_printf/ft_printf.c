/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:08:27 by ilazar            #+#    #+#             */
/*   Updated: 2024/05/17 16:51:24 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list				args;
	unsigned int		count_chars;

	va_start(args, s);
	count_chars = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			count_chars += print_arg(*++s, args);
			s++;
		}
		else
		{
			ft_putchar_fd(*s, 1);
			s++;
			count_chars++;
		}
	}
	va_end(args);
	return (count_chars);
}

int	print_arg(char c, va_list args)
{
	unsigned int	count_chars;

	count_chars = 0;
	if (c == 's')
		count_chars = print_str(args);
	else if (c == 'd' || c == 'i')
		count_chars = print_int(args);
	else if (c == 'c')
		count_chars = print_char(args);
	else if (c == '%')
		count_chars = print_precent();
	else if (c == 'u')
		count_chars = print_unsigned(args);
	else if (c == 'p' || c == 'x' || c == 'X')
		count_chars = getvar_ptrhex(args, c);
	return (count_chars);
}
/*
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int	chars;
	//int	a;
	char *test = "NULL %s NULL";
	
	//mine
	chars = ft_printf(test, NULL);
	printf("\nchars: %d\n", chars);

	printf("\n");

	//original
	chars = printf("NULL %s NULL", "");
	printf("\nchars: %d\n", chars);

	//printf("\n%d", a);
	return 0;
}*/