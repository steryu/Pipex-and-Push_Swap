#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*x;

	i = 0;
	x = ((char *)str);
	while (i < n)
	{
		x[i] = c;
		i++;
	}
	return (x);
}
