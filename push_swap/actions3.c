/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:01:04 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/01 10:33:38 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	bottom_to_top(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack_b)
{
	bottom_to_top(stack_b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b)
{
	bottom_to_top(stack_a);
	bottom_to_top(stack_b);
	write(1, "rrr\n", 4);
}
