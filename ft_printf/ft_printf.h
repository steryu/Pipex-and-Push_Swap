#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_print_string(char *s);
int		ft_print_hex(unsigned long n, char uplow);
int		ft_putnbr_un(unsigned int n);
int		ft_print_point(unsigned long n);
int		ft_convert(unsigned long n, char uplow);

#endif