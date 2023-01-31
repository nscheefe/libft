/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:17:06 by nscheefe          #+#    #+#             */
/*   Updated: 2022/10/26 20:03:44 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (start >= ft_strlen(s))
		return (ft_calloc(sizeof(char), 1));
	sub = malloc(sizeof(char ) * (len + 1));
	if (!sub)
		return (NULL);
	s += start;
	ft_strlcpy(sub, (char *)s, (len + 1));
	return (sub);
}
