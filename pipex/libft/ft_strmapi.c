#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = (*f)(i, str[i]);
		i++;
	}
	return (str);
}
