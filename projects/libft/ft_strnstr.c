#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	while ((haystack[i] != '\0') && (i < len))
	{
		while (((i + j) != (len) && (haystack[j + i] == needle[j])))
		{
			j++;
			if (j == (ft_strlen((needle))))
				return ((char *)(haystack + (i)));
		}
		j = 0;
		i++;
	}
	return (NULL);
}
