#include "ft_printf.h"
#include <stdarg.h>

int	get_format(char s, va_list args)
{
	if (s == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (s == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (s == 'd' || s == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (s == '%')
		return (ft_putchar('%'));
	if (s == 'x')
		return (print_hex(va_arg(args, unsigned int), 1));
	if (s == 'X')
		return (print_hex(va_arg(args, unsigned int), 0));
	if (s == 'p')
		return (print_p(va_arg(args, unsigned long)));
	if (s == 'u')
		return (print_u(va_arg(args, long int)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '\0')
			return (0);
		if (format[i] == '%')
		{
			len += get_format(format[i + 1], args);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int main(void)
{
    ft_printf("Magic %s is %5d", "number", 42);
}