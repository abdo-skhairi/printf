#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_printf(const char *str, ...);

int ft_putchar(char c);
int ft_putstr(char *s);
int ft_putnbr(int nbr);
int	ft_puthexa(unsigned long n, char format);
int	ft_unsigned(unsigned int n);

#endif