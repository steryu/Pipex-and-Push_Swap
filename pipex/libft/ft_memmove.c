#include "libft.h"

void	*ft_memmove(void *dst, const void *str, size_t n)
{
	int	i;

	i = 0;
	if (dst == str)
		return (dst);
	if (dst > str)
	{
		while (n)
		{
			((char *)dst)[n - 1] = ((char *)str)[n - 1];
			n--;
		}
		return (dst);
	}
	if (dst < str)
	{
		while (n)
		{
			((char *)dst)[i] = ((char *)str)[i];
			i++;
			n--;
		}
	}
	return (dst);
}
