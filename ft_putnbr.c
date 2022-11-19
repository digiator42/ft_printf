/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:08:42 by ahassan           #+#    #+#             */
/*   Updated: 2022/11/19 03:39:38 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int res = 0;
	if (n == -2147483648)
	{
		res += ft_putstr("-2147483648");
		return res;
	}
	if (n < 0)
	{
		res += ft_putchar('-');
		n *= -1;
	}
	if (n < 10 && n >= 0)
	{
		res += ft_putchar(n + '0');
		return res;
	}
	res += ft_putnbr(n / 10);
	res += ft_putnbr(n % 10);
	return res;
}
