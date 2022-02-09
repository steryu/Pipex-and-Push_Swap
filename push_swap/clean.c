/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:41:45 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/09 09:41:45 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
	{
		while (lst)
		{
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
		}
		lst = NULL;
	}
}

void	exit_error(t_stack *lst)
{
	write (2, "Error\n", 6);
	free_all(&lst);
	exit(EXIT_FAILURE);
}
