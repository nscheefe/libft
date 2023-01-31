/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:42:25 by nscheefe          #+#    #+#             */
/*   Updated: 2022/10/24 14:56:27 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2
			|| *s1 == '\0' || *s2 == '\0')
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
