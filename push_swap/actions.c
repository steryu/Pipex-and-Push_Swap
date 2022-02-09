/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:55:28 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/09 10:54:20 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (!stack)
		return ;
	swap_elem(&temp->value, &temp->next->value);
	swap_elem(&temp->index, &temp->next->index);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack_b)
{
	t_stack	*temp;

	temp = stack_b;
	if (!stack_b)
		return ;
	swap_elem(&temp->value, &temp->next->value);
	swap_elem(&temp->index, &temp->next->index);
	write(1, "sb\n", 3);
}

void	swap_a_b(t_stack *stack_a, t_stack *stack_b)
{
	swap_elem(&stack_a->value, &stack_a->next->value);
	swap_elem(&stack_a->index, &stack_a->next->index);
	swap_elem(&stack_b->value, &stack_b->next->value);
	swap_elem(&stack_b->index, &stack_b->next->index);
	write(1, "ss\n", 3);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top;

	if (!*stack_b)
		return ;
	top = *stack_b;
	*stack_b = top->next;
	top->next = *stack_a;
	*stack_a = top;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top;

	if (!*stack_a)
		return ;
	top = *stack_a;
	*stack_a = top->next;
	top->next = *stack_b;
	*stack_b = top;
	write(1, "pb\n", 3);
}
