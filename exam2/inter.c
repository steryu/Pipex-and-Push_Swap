#include <unistd.h>

char	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	same_char(char *str, char chr, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if(str[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int i;
	int	j;

	j = 0;
	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (same_char(argv[1], argv[1][i], i) == 0)
			{
				j = 0;
				while (argv[2][j])
				{
					if (argv[1][i] == argv[2][j])
					{
						ft_putchar(argv[1][i]);
						break ;
					}
					j++;
				}
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}