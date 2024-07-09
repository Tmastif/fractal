/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:09:10 by ilazar            #+#    #+#             */
/*   Updated: 2024/04/30 22:17:42 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_str(int digits, int n, int sign);
static char	*special_case(int n);

char	*ft_itoa(int n)
{
	int	digits;
	int	sign;
	int	nbr;

	if (n == 0 || n == -2147483648)
		return (special_case(n));
	digits = 0;
	if (n < 0)
	{
		sign = -1;
		n = n * -1;
		digits++;
	}
	nbr = n;
	while (nbr > 0)
	{
		digits++;
		nbr = nbr / 10;
	}
	return (make_str(digits, n, sign));
}

static char	*make_str(int digits, int n, int sign)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * digits + 1);
	if (str == NULL)
		return (NULL);
	if (sign == -1)
		str[0] = '-';
	str[digits] = '\0';
	while (n > 0)
	{
		digits--;
		str[digits] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

static char	*special_case(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup("-2147483648"));
}
