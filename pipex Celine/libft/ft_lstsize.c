#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;

	if (!lst)
		return (0);
	counter = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		counter++;
	}
	return (counter);
}
