#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*head;

	if (!lst || !f)
		return (0);
	head = 0;
	while (lst)
	{
		element = ft_lstnew(f(lst->content));
		if (!element)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, element);
		lst = lst->next;
	}
	return (head);
}
