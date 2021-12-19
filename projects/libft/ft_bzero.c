#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			counter;
	unsigned char	*x;

	x = (unsigned char *)s;
	counter = 0;
	while (counter != n)
	{
		x[counter] = '\0';
		counter++;
	}
}
