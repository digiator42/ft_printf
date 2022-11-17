/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:08:31 by ahassan           #+#    #+#             */
/*   Updated: 2022/11/18 02:34:22 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		ft_printf(char *input, ...);

char	print_char(int c)
{
	write(1, &c, 1);
	return (0);
}

int	print_str(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}

int	ft_printhex(char current, long long c)
{
	int	prints;

	prints = 1;
	if (c >= 16)
		prints += ft_printhex(current, c / 16);
	c %= 16;
	if (current == 'X')
		write(1, &"0123456789ABCDEF"[c], 1);
	else
		write(1, &"0123456789abcdef"[c], 1);
	return (prints);
}

int	ft_format(va_list args, char percent, char current)
{
	int	result;

	result = 0;
	if (current == 'd' || current == 'i' || current == 'u')
		ft_putnbr(va_arg(args, int));
	else if (current == 'c')
		ft_putchar(va_arg(args, int));
	else if (current == 'p')
	{
		ft_putstr("0x");
		result += ft_printhex(current, va_arg(args, unsigned long long));
	}
	else if (current == 's')
		ft_putstr(va_arg(args, char *));
	else if (current == 'x' || current == 'X')
		result += ft_printhex(current, va_arg(args, int));
	else if (current == '\n')
		print_str("%\n");
	else if (current == '%' || !current)
		print_char(percent);
	else //if current != all criteria, print both
		result += ft_printf("%c%c", percent, current);
	return (result);
}

int	ft_printf(char *input, ...)
{
	int		result;
	int		i;
	va_list	args;
	int		j;

	va_start(args, input);
	i = 0;
	result = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			j = i;
			result += ft_format(args, input[j], input[++i]);
		}
		else
			result += print_char(input[i]);
		i++;
	}
	va_end(args);
	return (result);
}

int	main(void)
{
	// int *i = 0;
	ft_printf("%d\nMohamed Monier\n%c\n%s\n", -12312313, 'a', "OMGGGGGGG");
	write(1, "--------------------\n", 22);
	printf("%d\nMohamed Monier\n%c\n%s\n", -12312313, 'a', "OMGGGGGGG");

	ft_printf("%%\nfdf\n%p\n%i\n%c\n%s\n%p\n", -32, __LONG_LONG_MAX__, 'c',
			"dd", (void *)__LONG_LONG_MAX__);
	write(1, "--------------------\n", 22);
	printf("%%\nfdf\n%p\n%i\n%c\n%s\n%p\n", -32, __LONG_LONG_MAX__, 'c', "dd",
			(void *)__LONG_LONG_MAX__);

	//
	//max handling for printing pointers is unsigned int 4,294,967,295 increased by 1

	//%\n new line is not printed
	ft_printf("Integers: %i %u \n", -3456, 3456);
	ft_printf("Characters: %c %c \n", 'z', 80);
	ft_printf("Decimals: %d %u\n", 1997, 32000L);
	ft_printf("==>: %kkkk\n");
	ft_printf("%s \n", "Educative");
	ft_printf("%"); // this is working on online compiler, linux not
	ft_printf("--------------\n");
	printf("Integers: %i %u \n", -3456, 3456);
	printf("Characters: %c %c \n", 'z', 80);
	printf("Decimals: %d %ld\n", 1997, 32000L);
	printf("==>: %kkkk\n");
	printf("%s \n", "Educative");
}