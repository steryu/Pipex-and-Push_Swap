#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	counter;
	char	*sub;

	if (!s)
		return (NULL);
	counter = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	while ((counter < len) && (start < (ft_strlen(s))))
	{
		sub[counter] = s[start + counter];
		counter++;
	}
	return (sub);
}
