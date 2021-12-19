#include "ft_printf.h"

int	print_hex(unsigned long n, int uplow)
{
	char	*s;
	int		len;

	if (uplow == 1)
		s = "0123456789abcdef";
	if (uplow == 0)
		s = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
	{
		len += print_hex(n / 16, uplow);
		len += print_hex(n % 16, uplow);
	}
	if ((n < 16) && (n >= 0))
		len += ft_putchar(s[n % 16]);
	return (len);
}
