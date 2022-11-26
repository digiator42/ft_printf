/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:03:18 by ahassan           #+#    #+#             */
/*   Updated: 2022/11/26 21:12:44 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#ifdef __linux__

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
#endif

#ifdef __APPLE__

int	ft_printpointer(char current, unsigned long long c)
{
	int	result;

	result = 0;
	result += ft_putstr("0x");
	result += ft_printhex(current, c);
	return (result);
}
#endif