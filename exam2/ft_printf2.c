#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}

void	ft_hex(unsigned int n, char *uplow)
{
	if (n != 0)
	{
		ft_hex(n / 16, uplow);
		ft_putchar(uplow[n % 16]);
	}
}

int	ft_convert(unsigned int n, char uplow)
{
	int i;
	char *low;
	char *up;

	low = "0123456789abcdef";
	i = 0;
	if (n == 0)
	{
		ft_putchar(low[n]);
		return (0);
	}
	ft_hex(n, low);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n < 10)
		ft_putchar(n + '0');
	count ++;
	return (count);
}

int	ft_string(char *s)
{
	int i;

	if (!s)
	{
		ft_string("(null)");
		return (6);
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return(i);
}

int	what_is_it(va_list arg, const char *format)
{
	int len;

	len = 0;
	if (*format == 'd')
		return(ft_putnbr(va_arg(arg, int)));
	if (*format == 's')
		return(ft_string(va_arg(arg, char *)));
	if (*format == 'x')
		return(ft_convert(va_arg(arg, unsigned int), 'a'));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int i;
	int len;
	va_list arg;

	i = 0;
	len = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '\0')
			return (0);
		if (format[i] == '%')
		{
			len += what_is_it(arg, &format[i + 1]);
			i++;
		}
		else 
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}

int main(void)
{
	ft_printf("mine %d\n", (ft_printf("-> %s\n", "ster")));
	printf("%d\n", (printf("-> %s\n", "ster")));
	return (0);
}