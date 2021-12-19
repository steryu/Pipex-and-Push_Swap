#include "ft_printf.h"

int	print_p(unsigned long n)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += print_hex(n, 1);
	return (len);
}
