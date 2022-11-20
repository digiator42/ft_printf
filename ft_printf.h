/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:20:29 by ahassan           #+#    #+#             */
/*   Updated: 2022/11/20 21:43:00 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int     ft_printf(const char *input, ...);
int     ft_format(va_list args, char percent, char current);
int     ft_putchar(char c);
int     ft_putstr(char *s);
int     ft_putnbr(int n);
int     ft_printhex(char current, unsigned long long c);
int     ft_printunsigned(unsigned int n);

#endif
