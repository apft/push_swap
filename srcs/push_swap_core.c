/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:28:11 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 12:01:42 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "opti.h"
#include "insertion_sort.h"

#define STACK_MIN_SIZE_ALGO	3

static void	set_node_to_top_a(t_data *stacks)
{
	int		min_a;
	int		index_min_a;
	int		dst_top;

	index_min_a = 0;
	min_a = stack_min(stacks->a, &index_min_a);
	dst_top = dst_to_top(index_min_a, stacks->size_a);
	while (stacks->a->value != min_a)
		apply_rotation(stacks, &dst_top, IS_STACK_A);
}

static void	insert_b(t_data *stacks, int value)
{
	pb(stacks, ADD_ACTION_LIST);
	if (value < stack_get_median(stacks->b))
		rb(stacks, ADD_ACTION_LIST);
}

static void	pb_all_smaller_median(t_data *stacks)
{
	int		size_a;
	int		median_a;

	size_a = stacks->size_a;
	median_a = stack_get_median(stacks->a);
	while (stacks->size_a > STACK_MIN_SIZE_ALGO
			&& size_a-- && !is_sort_stack(stacks->a))
	{
		if (stacks->a->value >= median_a)
			ra(stacks, ADD_ACTION_LIST);
		else
			insert_b(stacks, stacks->a->value);
	}
}

int			push_swap(t_data *stacks)
{
	stacks->size_a = size_stack(stacks->a);
	compute_scale_values(stacks->a);
	while (!is_sort_stack(stacks->a) && stacks->size_a > STACK_MIN_SIZE_ALGO)
		pb_all_smaller_median(stacks);
	if (stacks->size_a == STACK_MIN_SIZE_ALGO)
		sort_three_elements(stacks);
	if (stacks->b)
		insertion_sort(stacks);
	if (stacks->a)
		set_node_to_top_a(stacks);
	action_print(stacks->actions);
	return (1);
}
