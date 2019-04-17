/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <pion@student.42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:16:20 by apion             #+#    #+#             */
/*   Updated: 2019/04/17 16:30:19 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "core.h"
#include "libft.h"
#include "ft_printf.h"
#include "output.h"

#ifndef INT_MAX
# define INT_MAX	0x7fffffff
#endif

#define IS_STACK_A	1
#define IS_STACK_B	2

static int	dst_to_top(int index, int size)
{
	if (index <= size / 2)
		return (index);
	return (-(size - index));
}

static int	get_nbr_action(t_data *stacks, int index_next_a, int index_current_b)
{
	int		dst_a;
	int		dst_b;

	dst_a = dst_to_top(index_next_a, stacks->size_a);
	dst_b = dst_to_top(index_current_b, stacks->size_b);
	if (dst_a == dst_b)
		return (ft_abs(dst_a));
	if ((dst_a > 0 && dst_b > 0) || (dst_a < 0 && dst_b < 0))
		return (ft_max(ft_abs(dst_a), ft_abs(dst_b)));
	return (ft_abs(dst_a) + ft_abs(dst_b));
}

static void	search_next_a(t_stack *stack_a, int value_b, int *next_a)
{
	int		index;

	index = 0;
	next_a[0] = -1;
	next_a[1] = INT_MAX;
	while (stack_a)
	{
		if (stack_a->value > value_b && stack_a->value < next_a[1])
		{
			next_a[0] = index;
			next_a[1] = stack_a->value;
		}
		++index;
		stack_a = stack_a->next;
	}
}

static void	search_best_b(t_data *stacks, int *next_a, int *best_b)
{
	t_stack	*stack_b;
	int		tmp_next[2];
	int		index;
	int		best_nbr_action;

	next_a[1] = INT_MAX;
	stack_b = stacks->b;
	index = 0;
	best_nbr_action = INT_MAX;
	best_b[1] = stack_b->value;
	while (stack_b)
	{
		search_next_a(stacks->a, stack_b->value, tmp_next);
		if (tmp_next[1] < next_a[1]
				&& get_nbr_action(stacks, tmp_next[0], index) < best_nbr_action)
		{
			next_a[0] = tmp_next[0];
			next_a[1] = tmp_next[1];
			best_b[0] = index;
			best_b[1] = stack_b->value;
			best_nbr_action = get_nbr_action(stacks, next_a[0], best_b[0]);
		}
		++index;
		stack_b = stack_b->next;
	}
}

static void	apply_rotation(t_data *stacks, int *dst_to_top, int which_stack)
{
	if (!*dst_to_top)
		return ;
	else if (*dst_to_top < 0)
	{
		if (which_stack == IS_STACK_A)
			rra(stacks, ADD_ACTION_LIST);
		else if (which_stack == IS_STACK_B)
			rrb(stacks, ADD_ACTION_LIST);
		++(*dst_to_top);
	}
	else
	{
		if (which_stack == IS_STACK_A)
			ra(stacks, ADD_ACTION_LIST);
		else if (which_stack == IS_STACK_B)
			rb(stacks, ADD_ACTION_LIST);
		--(*dst_to_top);
	}
}

static void	push_back(t_data *stacks, int best_b[2], int next_a[2])
{
	int		dst_to_top_a;
	int		dst_to_top_b;

	dst_to_top_a = dst_to_top(next_a[0], stacks->size_a);
	dst_to_top_b = dst_to_top(best_b[0], stacks->size_b);
	while (stacks->a->value != next_a[1] || stacks->b->value != best_b[1])
	{
		apply_rotation(stacks, &dst_to_top_a, IS_STACK_A);
		apply_rotation(stacks, &dst_to_top_b, IS_STACK_B);
	}
	pa(stacks, ADD_ACTION_LIST);
}

void		insertion_sort(t_data *stacks)
{
	int		best_b[2];
	int		next_a[2];

	if (!stacks->a)
		return ;
	next_a[0] = 0;
	next_a[1] = stacks->a->value;
	while (stacks->b)
	{
		search_best_b(stacks, next_a, best_b);
		push_back(stacks, best_b, next_a);
	}
}
