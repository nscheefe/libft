/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:57:11 by nscheefe          #+#    #+#             */
/*   Updated: 2022/12/23 19:48:22 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int	ft_putchar(int c);
int	ft_putstr(char *c);
int	ft_putnbr(long long n);
int	ft_printf(const char *flag, ...);
int	ft_putbase(unsigned long long nb, const char flag, unsigned int base);
int	ft_numlen(unsigned long long arg, int base);
int	ft_flags(va_list args, const char flag);
int	ft_put_ptr(unsigned long long nb);

#endif
