/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:24:25 by nscheefe          #+#    #+#             */
/*   Updated: 2022/10/25 12:37:42 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(little);
	if (n == 0 || big == little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		n = 0;
		while (big[i + n] == little[n] && i + n < len && little[n] != '\0')
			n++;
		if (n == ft_strlen(little))
			return ((char *)big + i);
		i++;
	}
	return (0);
}
