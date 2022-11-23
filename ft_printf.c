/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:08:31 by ahassan           #+#    #+#             */
/*   Updated: 2022/11/23 07:44:54 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	int		result;
	int		i;
	va_list	args;

	va_start(args, input);
	i = 0;
	result = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%' && input[i + 1])
		{
			result += ft_format(args, input[++i]);
		}
		else
			result += ft_putchar(input[i]);
		i++;
	}
	va_end(args);
	return (result);
}
