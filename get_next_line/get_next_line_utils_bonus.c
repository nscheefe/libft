/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:30:57 by nscheefe          #+#    #+#             */
/*   Updated: 2022/12/23 19:56:26 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(const char *c)
{
	size_t	i;

	if (c == NULL)
		return (0);
	i = 0;
	while (*c++)
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (!(char)c)
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (*(char *)s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len;
	size_t	lens1;
	char	*new;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * ((ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1));
	if (!new)
		return (free(s1), NULL);
	lens1 = 0;
	len = 0;
	while (s1[lens1] != '\0')
	{
		new[lens1] = s1[lens1];
		lens1++;
	}
	while (s2[len] != '\0')
		new[lens1++] = s2[len++];
	new[lens1] = '\0';
	return (free (s1), new);
}

int	ft_count_line(char *temp)
{
	int	i;

	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero_gnl(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n--)
	{
		*str++ = '\0';
	}
	return ;
}
