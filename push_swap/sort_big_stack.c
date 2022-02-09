/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:40:25 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/09 10:59:34 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maximum_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_big_stack(t_stack **stack_a, int size)
{
	t_stack	*stack_b;
	int		i;
	int		j;
	int		max_bits;

	i = 0;
	stack_b = NULL;
	max_bits = maximum_bits(size - 1);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, &stack_b);
			j++;
		}
		while (stack_b)
			push_a(stack_a, &stack_b);
		i++;
	}	
	free_all(stack_a);
	exit(0);
}
