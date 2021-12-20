#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	char	*x;

	counter = 0;
	x = (char *)src;
	if (dstsize == 0)
		return (ft_strlen(x));
	while (counter != (dstsize - 1) && (src[counter] != '\0'))
	{
		dst[counter] = x[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (ft_strlen(x));
}
