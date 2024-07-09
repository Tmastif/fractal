/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:55:36 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/09 22:08:43 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static double ft_atodbl_fract(char *str, int sign, long integer);

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' || s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return(0);
        i++;
    }
    return (1);
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
        if (*str > '9' || *str < '1')
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
        if (*str > '9' || *str < '1')
            return ((integer + fraction) * sign);
        power /= 10;
        fraction += (*str - '0') * power;
        str++;
    }
    return ((integer + fraction) * sign);
}

