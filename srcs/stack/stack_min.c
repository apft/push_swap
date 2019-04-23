/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:49:31 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 12:08:31 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#ifndef INT_MIN
# define INT_MIN	0xffffffff
#endif

int		stack_min(t_stack *stack, int *index_min)
{
	int		min;
	int		index;

	if (!stack)
		return (INT_MIN);
	min = stack->value;
	index = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			*index_min = index;
		}
		++index;
		stack = stack->next;
	}
	return (min);
}
