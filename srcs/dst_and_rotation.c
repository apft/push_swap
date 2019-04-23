/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst_and_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:45:02 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:19:06 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insertion_sort.h"
#include "core.h"

int		dst_to_top(int index, int size)
{
	if (index <= size / 2)
		return (index);
	return (-(size - index));
}

void	apply_rotation(t_env *env, int *dst_to_top, int which_stack)
{
	if (!*dst_to_top)
		return ;
	else if (*dst_to_top < 0)
	{
		if (which_stack == IS_STACK_A)
			rra(env, ADD_ACTION_LIST);
		else if (which_stack == IS_STACK_B)
			rrb(env, ADD_ACTION_LIST);
		++(*dst_to_top);
	}
	else
	{
		if (which_stack == IS_STACK_A)
			ra(env, ADD_ACTION_LIST);
		else if (which_stack == IS_STACK_B)
			rb(env, ADD_ACTION_LIST);
		--(*dst_to_top);
	}
}
