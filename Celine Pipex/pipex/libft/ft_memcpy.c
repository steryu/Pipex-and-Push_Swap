#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			counter;
	unsigned char	*x;
	unsigned char	*k;

	counter = 0;
	x = (unsigned char *)dst;
	k = (unsigned char *)src;
	if ((x == NULL && (k == NULL)))
		return (0);
	while (counter != n)
	{
		x[counter] = k[counter];
		counter++;
	}
	return (x);
}
