
#include "ft_printf.h"

int ft_putchar(char c) 
{
	return(write(1, &c, 1));
}

int ft_putstr(char *s)
{
	int i;

	if(!s)
		return(ft_putstr("(null)"));
	i = 0;
	while(s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return(i);
}

int ft_putnbr(int nbr)
{
	int i;

	i = 0;
    if (nbr == -2147483648) 
	{
    	write(1, "-2147483648", 11);
		return(11);
    }
    else if (nbr < 0) 
	{
        i += ft_putchar('-');
        nbr = -nbr;
    }
    if (nbr > 9)
	{
        i += ft_putnbr(nbr / 10);
		i += ft_putchar((nbr % 10) + '0');
    }
	else
    	i += ft_putchar(nbr + '0');
	return(i);
}

int	ft_puthexa(unsigned long n, char format)
{
	int		count;
	char	*s;

	count = 0;
	if (format == 'x')
		s = "0123456789abcdef";
	if (format == 'X')
		s = "0123456789ABCDEF";
	if (n < 16)
		count += ft_putchar(s[n]);
	else
	{
		count += ft_puthexa(n / 16, format);
		count += ft_putchar(s[n % 16]);
	}
	return (count);
}

int ft_unsigned(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n < 10)
		i += ft_putchar(n + '0');
	else
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}