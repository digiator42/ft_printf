/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:44:17 by ahassan           #+#    #+#             */
/*   Updated: 2022/11/23 08:34:04 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(char current, unsigned long long c)
{
	int	result;

	result = 0;
	if (c == 0)
		result += ft_putstr("(nil)");
	else
	{
		result += ft_putstr("0x");
		result += ft_printhex(current, c);
	}
	return (result);
}

int	ft_format(va_list args, char current)
{
	int	result;

	result = 0;
	if (current == 'd' || current == 'i')
		result += ft_putnbr(va_arg(args, int));
	if (current == 'u')
		result += ft_printunsigned(va_arg(args, unsigned int));
	if (current == 'c')
		result += ft_putchar(va_arg(args, int));
	if (current == 's')
		result += ft_putstr(va_arg(args, char *));
	if (current == 'p')
		result += ft_printpointer(current, va_arg(args, unsigned long long));
	if (current == 'x' || current == 'X')
		result += ft_printhex(current, va_arg(args, unsigned int));
	if (current == '%')
		result += ft_putchar('%');
	return (result);
}
