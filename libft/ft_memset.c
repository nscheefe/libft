/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:23:48 by nscheefe          #+#    #+#             */
/*   Updated: 2022/10/17 13:55:03 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *str, int c, int n)
{
	unsigned char	*strr;

	strr = (unsigned char *)str;
	while (n--)
	{
		*strr++ = (unsigned char)c;
	}
	return (str);
}
