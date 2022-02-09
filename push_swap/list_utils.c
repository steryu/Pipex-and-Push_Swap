/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:46:39 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/08 14:12:56 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_a(t_stack *l)
{
	size_t	i;

	i = 0;
	while (l)
	{
		l = l->next;
		i++;
	}
	return (i);
}

t_stack	*new_stack(int value, int index)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->index = index;
	elem->next = NULL;
	return (elem);
}

int	a_is_storted(t_stack *list)
{
	t_stack	*l;

	l = list;
	if (list == NULL)
		return (1);
	while (l->next != NULL)
	{
		if (l->value > l->next->value)
			return (0);
		l = l->next;
	}
	return (1);
}
