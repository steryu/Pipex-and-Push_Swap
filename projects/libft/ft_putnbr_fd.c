#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	nb = (long long) n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putnbr_fd((nb % 10), fd);
	}
	if ((nb < 10) && (nb >= 0))
		ft_putchar_fd(nb + '0', fd);
}
