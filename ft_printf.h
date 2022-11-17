/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:20:29 by ahassan           #+#    #+#             */
/*   Updated: 2022/11/18 02:34:03 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int 				ft_printf(char *input, ...);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnbr(int n);
int	ft_printhex(char current, long long c);


#endif
