/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:08:48 by ilazar            #+#    #+#             */
/*   Updated: 2024/05/09 21:25:06 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
//#include <fcntl.h>

void	ft_putnbr_fd(long n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		c = (nbr % 10) + '0';
		ft_putchar_fd(c, fd);
	}
	else
	{
		c = nbr + '0';
		ft_putchar_fd(c, fd);
	}
}
/*
int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDWR);
	if (fd == -1)
	{
		printf("error with file\n");
		return (0);
	}
	ft_putnbr_fd(-999999, fd);
	close(fd);
	return (0);
}*/
