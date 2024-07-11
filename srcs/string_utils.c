/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:55:36 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/11 13:13:38 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double ft_atodbl_fract(char *str, int sign, long integer);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
double ft_atodbl(char *str)
{
    long integer;
    int sign;

    integer = 0;
    sign = 1;
    while ((*str >= 9 && *str <= 13) || *str == ' ')
        str++;
    while (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (*str && *str != '.')
    {
        if (*str > '9' || *str < '0')
            return (integer * sign);
        integer = (integer * 10) + (*str++ - '0');
    }
    if (*str++ == '.')
        return(ft_atodbl_fract(str, sign, integer));
    return (integer * sign);
}
static double ft_atodbl_fract(char *str, int sign, long integer)
{
    double  fraction;
    double  power;

    fraction = 0;
    power = 1;
    while (*str)
    {
        if (*str > '9' || *str < '0')
            return ((integer + fraction) * sign);
        power /= 10;
        fraction += (*str - '0') * power;
        str++;
    }
    return ((integer + fraction) * sign);
}

