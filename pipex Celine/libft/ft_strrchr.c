#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		counter;
	char	*x;

	x = (char *)s;
	counter = ft_strlen(x);
	while (counter > -1)
	{
		if ((char)c == x[counter])
			return (&x[counter]);
		counter--;
	}
	return (NULL);
}
