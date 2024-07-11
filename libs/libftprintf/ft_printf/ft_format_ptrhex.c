/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_ptrhex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:53:41 by ilazar            #+#    #+#             */
/*   Updated: 2024/05/17 16:49:43 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	recurs_dectohex(unsigned long long int dec, char x);
static int	print_ptrhex(unsigned long long int ptrdec, char x);

int	getvar_ptrhex(va_list args, char x)
{
	unsigned long long int	dec;
	unsigned int			count_chars;

	dec = va_arg(args, unsigned long long int);
	if (x == 'p')
		count_chars = print_ptrhex(dec, 'p');
	else
	{
		dec = (unsigned int) dec;
		if (x == 'x')
			count_chars = print_ptrhex(dec, 'x');
		else
			count_chars = print_ptrhex(dec, 'X');
	}
	return (count_chars);
}

static int	print_ptrhex(unsigned long long int dec, char x)
{
	unsigned int	count_chars;

	count_chars = 0;
	if (x == 'p')
	{
		if (dec == 0)
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		ft_putstr_fd("0x", 1);
		count_chars = 2;
	}
	else if (dec == 0)
	{
		ft_putnbr_fd(0, 1);
		return (count_chars + 1);
	}
	count_chars += recurs_dectohex(dec, x);
	return (count_chars);
}

static int	recurs_dectohex(unsigned long long int dec, char x)
{
	int	count;
	int	reminder;

	if (dec == 0)
		return (0);
	reminder = dec % 16;
	count = recurs_dectohex(dec / 16, x);
	if (reminder <= 9)
		ft_putnbr_fd(reminder, 1);
	else
	{
		if (x == 'x' || x == 'p')
			ft_putchar_fd(reminder + 87, 1);
		else
			ft_putchar_fd(reminder + 55, 1);
	}
	return (count + 1);
}
