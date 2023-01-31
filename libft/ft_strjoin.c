/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:28:46 by nscheefe          #+#    #+#             */
/*   Updated: 2022/11/17 20:39:00 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	lens1;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	len = lens1 + ft_strlen(s2);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_memmove(new, s1, lens1);
	ft_memmove(new + lens1, s2, ft_strlen(s2));
	new[len] = '\0';
	return (new);
}
