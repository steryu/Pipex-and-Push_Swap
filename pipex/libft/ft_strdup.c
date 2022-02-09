#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	n;

	n = (ft_strlen(s1) + 1);
	dst = malloc(n);
	if (!dst)
		return (0);
	ft_memcpy(dst, s1, n);
	return (dst);
}
