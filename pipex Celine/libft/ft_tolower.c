int	ft_tolower(int c)
{
	int	counter;

	counter = 0;
	if ((c >= 'A') && (c <= 'Z'))
		c += 32;
	else
		return (c);
	return (c);
}
