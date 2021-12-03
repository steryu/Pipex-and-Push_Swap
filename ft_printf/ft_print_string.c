#include "ft_printf.h"

int	ft_print_string(char *s)
{
	int	i;

	if (!s)
	{
		ft_print_string("(null)");
		return (6);
	}
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}
