/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:42:28 by ahassan           #+#    #+#             */
/*   Updated: 2022/11/23 08:29:27 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(char current, unsigned long long c)
{
	int	result;

	result = 1;
	if (c >= 16)
		result += ft_printhex(current, c / 16);
	c %= 16;
	if (current == 'X')
		write(1, &"0123456789ABCDEF"[c], 1);
	else
		write(1, &"0123456789abcdef"[c], 1);
	return (result);
}
