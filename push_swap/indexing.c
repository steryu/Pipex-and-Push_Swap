/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:41:47 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/03 11:02:12 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*next_index(t_stack *list)
{
	t_stack	*lowest;
	t_stack	*temp;

	temp = list;
	while (temp)
	{
		if (temp->index < 0)
		{
			lowest = new_stack(temp->value, temp->index);
			break ;
		}
		temp = temp->next;
	}
	while (list)
	{
		if (list->value < lowest->value && list->index < 0)
		{
			lowest->value = list->value;
			lowest->index = list->index;
		}
		list = list->next;
	}
	return (lowest);
}

void	indexing(t_stack **stack)
{
	t_stack	*lowest;
	t_stack	*temp;
	int		i;
	int		size;

	i = 0;
	size = size_of_a(*stack);
	while (i < size)
	{
		temp = *stack;
		lowest = next_index(*stack);
		while (temp)
		{
			if (temp->value == lowest->value)
			{
				temp->index = i;
				break ;
			}
			temp = temp->next;
		}
		free(lowest);
		i++;
	}
}
