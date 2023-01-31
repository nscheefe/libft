/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:22:27 by nscheefe          #+#    #+#             */
/*   Updated: 2022/10/26 12:36:51 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	long long	ret;
	int			mop;

	ret = 0;
	mop = 1;
	while ((*nptr == ' ') || (*nptr == '\t') || (*nptr == '\r'
		) || (*nptr == '\n') || (*nptr == '\v') || (*nptr == '\f'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			mop *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		ret = 10 * ret + (*nptr - '0');
		nptr++;
	}
	return ((long long)ret * mop);
}
