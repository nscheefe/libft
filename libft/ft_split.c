/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:39:36 by nscheefe          #+#    #+#             */
/*   Updated: 2022/10/26 19:59:30 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str(char *s, size_t start, size_t end)
{
	char	*strr;
	size_t	i;

	i = 0;
	strr = ft_calloc(sizeof(char), ((end - start) + 1));
	while (start < end)
	{
		strr[i] = s[start];
		start++;
		i++;
	}
	strr[i] = '\0';
	return (strr);
}

static size_t	countword(char const *s, char c)
{
	size_t	i;
	size_t	o;
	size_t	j;

	i = 0;
	o = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			o = i;
			while (s[o] != c && s[o] != '\0')
				o++;
			j++;
			i = o - 1;
		}
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	o;
	size_t	j;
	char	**ret;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	ret = ft_calloc(sizeof(char *), (countword(s, c) + 1));
	if (!ret)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			o = i;
			while (s[o] != c && s[o] != '\0')
				o++;
			ret[j++] = str((char *)s, i, o);
			i = o - 1;
		}
	}
	ret[j] = NULL;
	return (ret);
}
