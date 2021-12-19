#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;

	first = NULL;
	new = NULL;
	if (!lst || !f)
		return (first);
	while (lst)
	{
		first = ft_lstnew(f(lst->content));
		if (!first)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, first);
		lst = lst->next;
	}
	return (new);
}
