#include "ft_printf.h"
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int		counter;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	counter = 0;
	while ((s[counter] != '\0') && (s))
	{
		write(1, &s[counter], 1);
		counter++;
	}
	return (ft_strlen(s));
}
