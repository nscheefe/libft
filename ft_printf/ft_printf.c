/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:22:57 by nscheefe          #+#    #+#             */
/*   Updated: 2022/12/23 19:48:26 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_flags(va_list args, const char flag)
{
	int	length;

	length = 0;
	if (flag == 'c')
		length += ft_putchar(va_arg(args, int));
	if (flag == 's')
		length += ft_putstr(va_arg(args, char *));
	if (flag == 'p')
		length += ft_put_ptr(va_arg(args, unsigned long long));
	if (flag == 'd' || flag == 'i')
		length += ft_putnbr(va_arg(args, long long));
	if (flag == 'u')
		length += ft_putbase(va_arg(args, unsigned int), flag, 10);
	if (flag == 'x' || flag == 'X')
		length += ft_putbase(va_arg(args, unsigned int), flag, 16);
	if (flag == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *flag, ...)
{
	int		num_args;
	int		i;
	int		length;
	va_list	args;

	num_args = ft_strlen(flag);
	va_start(args, flag);
	i = 0;
	length = 0;
	while (i < num_args)
	{
		if (flag[i] == '%')
		{
			i++;
			length += ft_flags(args, flag[i]);
		}
		else
			length += ft_putchar(flag[i]);
		i++;
	}
	va_end(args);
	return (length);
}
