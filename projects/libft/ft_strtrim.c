#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	counter;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	counter = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[counter]) && (s1[counter] != '\0'))
		counter++;
	while ((ft_strchr(set, s1[end - 1])) && (s1[counter] != '\0'))
		end--;
	s2 = malloc(end - counter + 1);
	if (!s2)
		return (NULL);
	while (counter != end)
		s2[start++] = s1[counter++];
	s2[start] = '\0';
	return (s2);
}
