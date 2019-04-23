/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:28:11 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:27:19 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "opti.h"
#include "insertion_sort.h"

#define STACK_MIN_SIZE_ALGO	3

static void	set_node_to_top_a(t_env *env)
{
	int		min_a;
	int		index_min_a;
	int		dst_top;

	index_min_a = 0;
	min_a = stack_min(env->stack_a, &index_min_a);
	dst_top = dst_to_top(index_min_a, env->size_a);
	while (env->stack_a->value != min_a)
		apply_rotation(env, &dst_top, IS_STACK_A);
}

static void	insert_b(t_env *env, int value)
{
	pb(env, ADD_ACTION_LIST);
	if (value < stack_get_median(env->stack_b))
		rb(env, ADD_ACTION_LIST);
}

static void	pb_all_smaller_median(t_env *env)
{
	int		size_a;
	int		median_a;

	size_a = env->size_a;
	median_a = stack_get_median(env->stack_a);
	while (env->size_a > STACK_MIN_SIZE_ALGO
			&& size_a-- && !is_sort_stack(env->stack_a))
	{
		if (env->stack_a->value >= median_a)
			ra(env, ADD_ACTION_LIST);
		else
			insert_b(env, env->stack_a->value);
	}
}

int			push_swap(t_env *env)
{
	env->size_a = size_stack(env->stack_a);
	compute_scale_values(env->stack_a);
	while (!is_sort_stack(env->stack_a) && env->size_a > STACK_MIN_SIZE_ALGO)
		pb_all_smaller_median(env);
	if (env->size_a == STACK_MIN_SIZE_ALGO)
		sort_three_elements(env);
	if (env->stack_b)
		insertion_sort(env);
	if (env->stack_a)
		set_node_to_top_a(env);
	action_print(env->actions);
	return (1);
}
