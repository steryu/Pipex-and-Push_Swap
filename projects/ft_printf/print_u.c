#include "ft_printf.h"

int	print_u(unsigned int n)
{
	unsigned long	nb;
	int				len;

	nb = (unsigned long) n;
	len = 0;
	if (nb >= 10)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	if ((nb < 10) && (nb >= 0))
		len += ft_putchar(nb + '0');
	return (len);
}
