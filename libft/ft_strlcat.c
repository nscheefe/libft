/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:24:05 by nscheefe          #+#    #+#             */
/*   Updated: 2022/10/24 15:02:48 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size )
{
	size_t	i;
	size_t	n;

	n = ft_strlen(src);
	if (size == 0)
		return (n);
	i = ft_strlen(dest);
	if (size < i)
		return (n + size);
	while (*src && (i + 1) < size)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}
