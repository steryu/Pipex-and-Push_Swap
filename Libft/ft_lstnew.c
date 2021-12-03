#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list1;

	list1 = (t_list *)malloc(sizeof(*list1));
	if (!list1)
		return (NULL);
	list1->content = content;
	list1->next = NULL;
	return (list1);
}
