#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	counter;
	size_t	counter2;

	if (!s1 || !s2)
		return (NULL);
	counter = 0;
	counter2 = 0;
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (counter != ft_strlen(s1))
	{
		s3[counter] = s1[counter];
		counter++;
	}
	while (counter2 != ft_strlen(s2))
	{
		s3[counter + counter2] = s2[counter2];
		counter2++;
	}
	s3[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (s3);
}
