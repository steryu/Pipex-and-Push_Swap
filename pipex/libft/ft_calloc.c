#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size * sizeof(char));
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
