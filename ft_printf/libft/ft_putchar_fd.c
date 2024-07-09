/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:08:48 by ilazar            #+#    #+#             */
/*   Updated: 2024/05/01 21:13:20 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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
	ft_putchar_fd('y', fd);
	close(fd);
	return (0);
}*/
