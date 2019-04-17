/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:28:11 by apion             #+#    #+#             */
/*   Updated: 2019/04/17 12:57:12 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "algo.h"
#include "opti.h"
#include "ft_printf.h"

int		stack_max(t_stack *stack)
{
	int		max;

	max = 0;
	while (stack)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int		stack_get_index_via_index(t_stack *stack, int index)
{
	int		i;

	i = 0;
	while (stack && stack->index != index)
	{
		++i;
		stack = stack->next;
	}
	return (i);
}

int		get_index_value_insert_before(t_stack *stack, int index)
{
	t_stack	*copy;
	int		index_min_bigger;

	copy = stack;
	index_min_bigger = stack_max(stack);
	while (stack)
	{
		if (stack->index > index)
			if (stack->index < index_min_bigger)
				index_min_bigger = stack->index;
		stack = stack->next;
	}
	return (stack_get_index_via_index(copy, index_min_bigger));
}

int		*compute_array_dst_to_top(t_data *stacks)
{
	int		i;
	int		*array_dst;
	int		index_a;
	t_stack	*stack_b;

	array_dst = (int *)malloc(sizeof(*array_dst) * stacks->size_b);
	if (!array_dst)
		return (0);
	stack_b = stacks->b;
	i = 0;
	while (stack_b)
	{
		index_a = get_index_value_insert_before(stacks->a, stack_b->index);
		array_dst[i] = dst_to_top(index_a, size_stack(stacks->a));
		++i;
		stack_b = stack_b->next;
	}
	return (array_dst);
}

int		get_min_index_b(int *array_dst_to_top, int size)
{
	int		min;
	int		dst;
	int		i;

	i = 0;
	min = i;
	while (i < size)
	{
		dst = ft_abs(array_dst_to_top[i]) + ft_abs(dst_to_top(i, size));
		if (dst < min)
			min = i;
		++i;
	}
	return (min);
}

void	insert_b(t_data *stacks, int value)
{
	pb(stacks, ADD_ACTION_LIST);
	if (value < stack_get_median(stacks->b))
		rb(stacks, ADD_ACTION_LIST);
//	else if (stacks->b->next && (index + 1) == stacks->b->next->index)
//		sb(stacks, ADD_ACTION_LIST);
}

void		set_node_to_top_a(t_data *stacks, int index)
{
	int		dst;

	dst = dst_to_top(stack_get_index_via_index(stacks->a, index), stacks->size_a);
	apply_action_n_times(stacks, ft_abs(dst), (dst < 0 ? rra : ra));
}

void	pb_all_smaller_median(t_data *stacks)
{
	int		size_a;
	int		median_a;

	size_a = size_stack(stacks->a);
	median_a = stack_get_median(stacks->a);
	while (stacks->size_a > 3 && size_a-- && !is_sort_stack(stacks->a))
	{
		if (stacks->a->value >= median_a)
			ra(stacks, ADD_ACTION_LIST);
		else
			insert_b(stacks, stacks->a->value);
	}
}

void	insertion_sort(t_data *stacks);
int			push_swap(t_data *stacks)
{
	compute_scale_values(stacks->a);
	stacks->size_a = size_stack(stacks->a);
	while (!is_sort_stack(stacks->a) && stacks->size_a > 3)
		pb_all_smaller_median(stacks);
	if (stacks->size_a == 3)
		sort_three_elements(stacks);
	if (stacks->b)
		insertion_sort(stacks);
	if (stack_get_index_via_index(stacks->a, 0) != 0)
		set_node_to_top_a(stacks, 0);
	action_print(stacks->actions);
	return (1);
}
