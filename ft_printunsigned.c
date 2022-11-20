/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:41:48 by ahassan           #+#    #+#             */
/*   Updated: 2022/11/20 02:05:28 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		res += ft_putchar('-');
		n *= -1;
	}
	if (n < 10 && n >= 0)
	{
		res += ft_putchar(n + '0');
		return (res);
	}
	res += ft_putnbr(n / 10);
	res += ft_putnbr(n % 10);
	return (res);
}
