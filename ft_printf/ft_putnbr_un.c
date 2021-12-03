#include "ft_printf.h"

int	ft_putnbr_un(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr_un(n / 10);
		ft_putnbr_un(n % 10);
	}
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	count++;
	return (count);
}
