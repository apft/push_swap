/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <pion@student.42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:16:20 by apion             #+#    #+#             */
/*   Updated: 2019/04/17 17:26:47 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "insertion_sort.h"
#include "libft.h"

#ifndef INT_MAX
# define INT_MAX	0x7fffffff
#endif

static int	get_nbr_action(t_data *stacks, int index_next_a,
							int index_current_b)
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
