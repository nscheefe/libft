/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:27:23 by nscheefe          #+#    #+#             */
/*   Updated: 2022/10/25 12:47:02 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	isize(long nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	i;
	long	nbr;

	nbr = n;
	i = isize(nbr);
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	ret[i--] = '\0';
	if (nbr < 0)
	{
		ret[0] = '-';
		nbr = nbr * -1;
	}
	if (nbr == 0)
		ret[0] = '0';
	while (nbr > 0)
	{
		ret[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
		i--;
	}
	return (ret);
}
