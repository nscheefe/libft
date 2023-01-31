/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:56:07 by nscheefe          #+#    #+#             */
/*   Updated: 2022/12/23 19:47:53 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
		c = "(null)";
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long long n)
{
	char	*out;
	int		len;

	len = 0;
	out = ft_itoa(n);
	ft_putstr (out);
	len = ft_strlen(out);
	free(out);
	return (len);
}

int	ft_numlen(unsigned long long arg, int base)
{
	int	i;

	i = 0;
	while (arg)
	{
		i++;
		arg = arg / base;
	}
	return (i);
}

int	ft_putbase(unsigned long long int nb, const char flag, unsigned int base)
{
	int	len;

	len = ft_numlen(nb, base);
	if (nb == 0)
		len = 1;
	if (nb >= base)
	{
		ft_putbase(nb / base, flag, base);
		ft_putbase(nb % base, flag, base);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd(nb + '0', 1);
		else if (nb > 0)
		{
			if (flag == 'X')
				ft_putchar_fd(nb - 10 + 'A', 1);
			if (flag == 'x' || flag == 'p')
				ft_putchar_fd(nb - 10 + 'a', 1);
		}
	}
	return (len);
}

int	ft_put_ptr(unsigned long long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len += write(1, "0x0", 3);
	else
	{
		len += write(1, "0x", 2);
		len += ft_putbase(nb, 'p', 16);
	}
	return (len);
}
