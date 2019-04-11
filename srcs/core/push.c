/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:02:58 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 15:45:34 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		pa(t_data *stacks)
{
	action_add_first(&stacks->actions, "pa");
	if (stack_push(&stacks->b, &stacks->a))
	{
		stacks->median_a = get_median(stacks->a);
		return (1);
	}
	return (0);
}

int		pb(t_data *stacks)
{
	action_add_first(&stacks->actions, "pb");
	if (stack_push(&stacks->a, &stacks->b))
	{
		stacks->median_b = get_median(stacks->b);
		return (1);
	}
	return (0);
}
