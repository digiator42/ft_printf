/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:44:17 by ahassan           #+#    #+#             */
/*   Updated: 2022/11/26 21:02:13 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char current)
{
	int	result;

	result = 0;
	if (current == 'd' || current == 'i')
		result += ft_putnbr(va_arg(args, int));
	else if (current == 'u')
		result += ft_printunsigned(va_arg(args, unsigned int));
	else if (current == 'c')
		result += ft_putchar(va_arg(args, int));
	else if (current == 's')
		result += ft_putstr(va_arg(args, char *));
	else if (current == 'p')
		result += ft_printpointer(current, va_arg(args, unsigned long long));
	else if (current == 'x' || current == 'X')
		result += ft_printhex(current, va_arg(args, unsigned int));
	else if (current == '%')
		result += ft_putchar('%');
	else
		result += ft_putchar(current);
	return (result);
}
