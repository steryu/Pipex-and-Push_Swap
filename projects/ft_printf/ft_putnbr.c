#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long long	nb;
	int			len;

	nb = (long long) n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	if ((nb < 10) && (nb >= 0))
		len += ft_putchar(nb + '0');
	return (len);
}
