#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (0);
	i = start;
	j = 0;
	while (ft_strlen(s) >= start && j < len)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
