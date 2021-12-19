#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			counter;
	unsigned char	*x;

	counter = 0;
	x = (unsigned char *)b;
	while (counter != len)
	{
		x[counter] = c;
		counter++;
	}
	return (b);
}
