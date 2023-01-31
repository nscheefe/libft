/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:23:35 by nscheefe          #+#    #+#             */
/*   Updated: 2022/10/17 14:53:34 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (dest == src || n == 0)
		return (dest);
	if (!dest && !src)
	{
		return (0);
	}
	while (n--)
	{
		((char *)dest)[n] = ((const char *)src)[n];
	}
	return (dest);
}
