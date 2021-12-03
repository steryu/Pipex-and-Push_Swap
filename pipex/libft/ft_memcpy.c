#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;
	char	*s;

	i = 0;
	dst = (char *)dest;
	s = (char *)src;
	if (dst == src || n == 0)
	{
		return (dest);
	}
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}
