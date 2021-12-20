int	ft_isalnum(int argument)
{
	if ((argument >= '0') && (argument <= '9'))
		return (1);
	if ((argument > 64) && (argument < 91))
		return (1);
	if ((argument > 96) && (argument < 123))
		return (1);
	return (0);
}
