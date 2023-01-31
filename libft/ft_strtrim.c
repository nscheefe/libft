/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:04:59 by nscheefe          #+#    #+#             */
/*   Updated: 2022/10/25 16:23:15 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	is_set(char s, char const *set)
{
	while (*set)
		if (s == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	len;
	size_t	start;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) - 1;
	start = 0;
	while ((is_set(s1[start], set)) == 1)
		start++;
	if (start >= len)
		return (ft_strdup(""));
	while ((is_set(s1[len], set)) == 1)
		len--;
	ret = ft_substr(s1, start, (len + 1 - start));
	return (ret);
}
