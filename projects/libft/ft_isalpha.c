int	ft_isalpha(int argument)
{
	if ((argument > 64) && (argument < 91))
		return (1);
	if ((argument > 96) && (argument < 123))
		return (1);
	return (0);
}
