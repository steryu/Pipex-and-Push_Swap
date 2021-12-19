#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		get_format(char s, va_list args);
int		ft_strlen(char *s);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		print_hex(unsigned long n, int uplow);
int		print_p(unsigned long n);
int		print_u(unsigned int n);

#endif