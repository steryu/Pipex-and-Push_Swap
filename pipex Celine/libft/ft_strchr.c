#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	counter;
	char	*x;

	x = (char *)s;
	counter = 0;
	while (counter != ft_strlen((char *)s) + 1)
	{
		if ((char)c == x[counter])
			return (&x[counter]);
		counter++;
	}
	return (NULL);
}
