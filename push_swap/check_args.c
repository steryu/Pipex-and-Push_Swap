/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:41:41 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/08 09:47:03 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_same_value(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	put_in_list(t_stack **stack, int value, int index)
{	
	t_stack	*elem;
	t_stack	*last;

	last = *stack;
	if (check_same_value(*stack, value))
		exit_error(*stack);
	elem = new_stack(value, index);
	if (*stack == NULL)
	{
		*stack = elem;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = elem;
}

void	check_args(int argc, char **argv, t_stack **stack)
{
	int	i;
	int	j;
	int	prev_num;

	i = 1;
	while (i < argc)
	{
		prev_num = 1;
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '+' && argv[i][j] != '-' && argv[i][j] != ' ' \
			&& !ft_isdigit(argv[i][j]))
				exit_error(*stack);
			if (prev_num == 1)
				put_in_list((stack), ft_atoi(&argv[i][j], *stack), -1);
			prev_num = 0;
			j++;
		}
		i++;
	}
}
