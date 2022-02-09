/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:00:26 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/09 10:54:29 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	top_to_bottom(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack_b)
{
	top_to_bottom(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_a_b(t_stack **stack_a, t_stack **stack_b)
{
	top_to_bottom(stack_a);
	top_to_bottom(stack_b);
	write(1, "rr\n", 3);
}
