int	ft_toupper(int c)
{
	int	counter;

	counter = 0;
	if ((c >= 'a') && (c <= 'z'))
		c -= 32;
	else
		return (c);
	return (c);
}
