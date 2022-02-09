/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:46:56 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/09 10:57:53 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}			t_stack;

int		main(int argc, char **argv);
void	sort_small_stack(t_stack *stack);

/* check arguments */
void	check_args(int argc, char **argv, t_stack **stack);

/* indexing */
t_stack	*next_index(t_stack *list);
void	indexing(t_stack **stack);

/* list utils */
int		size_of_a(t_stack *l);
int		a_is_storted(t_stack *list);
t_stack	*new_stack(int value, int index);

/* utils */
int		check_min_max(const char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str, t_stack *stack);
size_t	ft_strlen(const char *str);

/* under 5 stacks */
void	three_numbers(t_stack **stack);
void	four_numbers(t_stack **stack_a, int nb);
void	five_numbers(t_stack **stack);

/* above 5 */
void	sort_big_stack(t_stack **stack_a, int size);

/* actions utils */
void	swap_elem(int *a, int *b);
void	top_to_bottom(t_stack **stack);
void	bottom_to_top(t_stack **stack);

/* actions */
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack_b);
void	swap_a_b(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack_b);
void	rotate_a_b(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b);

/* error */
void	exit_error(t_stack *lst);
void	free_all(t_stack **lst);

#endif