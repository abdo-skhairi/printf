/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabderra <sabderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:23:57 by sabderra          #+#    #+#             */
/*   Updated: 2024/11/17 18:34:24 by sabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	printformat(char c, va_list ap)
{
	int i;

	i = 0;
	if(c == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if(c == 'u')
		i += ft_unsigned(va_arg(ap, unsigned int));
	else if((c == 'd') || (c == 'i'))
		i += ft_putnbr(va_arg(ap, int));
	else if((c == 'x') || (c == 'X'))
		i += ft_puthexa(va_arg(ap, unsigned int), c);
	else if(c == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if(c == 'p')
	{
		i += ft_putstr("0x");
		i += ft_puthexa(va_arg(ap, unsigned long), 'x');
	}
	else
		i += ft_putchar(c);
	return(i);
}

int	ft_printf(const char *f, ...)
{
	va_list ap;

	va_start(ap, f);
	int i = 0;
	int count = 0;
	while(f[i])
	{
		if (f[i] == '%')
		{
			i++;
			count = count + printformat(f[i], ap);
		}
		else
			count = count + write(1, &f[i], 1);
		i++;
	}
	return(count);
}
