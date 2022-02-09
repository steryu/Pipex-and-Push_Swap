/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:46:43 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/09 10:59:58 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_lowest_pos(t_stack *stack_a, int nb)
{
	t_stack	*stack_b;
	t_stack	*temp;
	int		pos;

	pos = 1;
	temp = stack_a;
	stack_b = NULL;
	while (temp)
	{
		if (temp->index == 0 && nb == 0)
			return (pos);
		if (temp->index == 1 && nb == 1)
			return (pos);
		temp = temp->next;
		pos++;
	}
	return (pos);
}

void	five_numbers(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		lowest_pos;

	stack_b = NULL;
	lowest_pos = search_lowest_pos(*stack_a, 0);
	if (lowest_pos == 2)
		swap_a(*stack_a);
	if (lowest_pos == 3)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	if (lowest_pos == 4)
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	if (lowest_pos == 5)
		reverse_rotate_a(stack_a);
	push_b(stack_a, &stack_b);
	four_numbers(stack_a, 1);
	push_a(stack_a, &stack_b);
}

void	four_numbers(t_stack **stack_a, int nb)
{
	t_stack	*stack_b;
	int		lowest_pos;

	stack_b = NULL;
	lowest_pos = search_lowest_pos(*stack_a, nb);
	if (lowest_pos == 2)
		swap_a(*stack_a);
	if (lowest_pos == 3)
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	if (lowest_pos == 4)
		reverse_rotate_a(stack_a);
	push_b(stack_a, &stack_b);
	three_numbers(stack_a);
	push_a(stack_a, &stack_b);
}

void	three_numbers(t_stack **stack)
{
	t_stack	*temp;
	int		top;
	int		middle;
	int		bottom;

	temp = *stack;
	top = temp->value;
	middle = temp->next->value;
	bottom = temp->next->next->value;
	if (bottom > top && top > middle)
		swap_a(*stack);
	else if (top > middle && middle > bottom)
	{
		swap_a(*stack);
		reverse_rotate_a(stack);
	}
	else if (top > bottom && bottom > middle)
		rotate_a(stack);
	else if (middle > bottom && bottom > top)
	{
		swap_a(*stack);
		rotate_a(stack);
	}
	else if (middle > top && top > bottom)
		reverse_rotate_a(stack);
}

void	sort_small_stack(t_stack *stack)
{
	if (size_of_a(stack) == 2)
		swap_a(stack);
	if (size_of_a(stack) == 3)
	{
		three_numbers(&stack);
	}
	if (size_of_a(stack) == 4)
	{
		four_numbers(&stack, 0);
	}
	if (size_of_a(stack) == 5)
	{
		five_numbers(&stack);
	}
	free_all(&stack);
	exit(0);
}
