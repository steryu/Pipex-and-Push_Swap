t_map	*ft_mapnew(int x, int y, char c)
{
	t_map	*map1;

	map1 = (t_map *)malloc(sizeof(*map1));
	if (!map1)
		return (NULL);
	map1->x = x;
	map1->y = y;
	map1->c = c;
	map1->next = NULL;
	return (map1);
}

void	ft_mapadd_back(t_map **map, t_map *new)
{
	t_map	*new_last;

	if (map)
	{
		if (*map)
		{
			new_last = ft_maplast(*map);
			new_last->next = new;
		}
		else
			*map = new;
	}
}

t_map	*ft_maplast(t_map *map)
{
	while (map != NULL)
	{
		if (map->next == NULL)
			return (map);
		map = map->next;
	}
	return (map);
}

void	ft_mapclear(t_map **map, void(*del)(void *))
{
	t_map	*temp;

	if (!*map)
		return;
	while (*map)
	{
		temp = (*map)->next;
		free(*map);
		*map = temp;
	}
	*map = NULL;
}
