/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:21:29 by nscheefe          #+#    #+#             */
/*   Updated: 2022/10/26 12:37:57 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	out;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n == -2147483648)
	{
		write(fd, "2147483648", 10);
		return ;
	}
	if (n < 10)
	{
		out = n + '0';
		write(fd, &out, 1);
	}
	else
	{
		out = (n % 10) + '0';
		ft_putnbr_fd(n / 10, fd);
		write(fd, &out, 1);
	}
}
