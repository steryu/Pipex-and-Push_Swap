/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:15:33 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/08 13:58:32 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc <= 1)
		return (0);
	check_args(argc, argv, &stack_a);
	if (!a_is_storted(stack_a))
	{
		indexing(&stack_a);
		if (size_of_a(stack_a) <= 5)
			sort_small_stack(stack_a);
		else
			sort_big_stack(&stack_a, size_of_a(stack_a));
	}
	free_all(&stack_a);
	return (0);
}
