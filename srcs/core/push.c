/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:02:58 by apion             #+#    #+#             */
/*   Updated: 2019/04/12 17:46:21 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			pa(t_data *stacks)
{
	action_add_first(&stacks->actions, "pa");
	if (stack_push(&stacks->b, &stacks->a))
	{
		stacks->size_a += 1;
		stacks->size_b -= 1;
		return (1);
	}
	return (0);
}

int			pb(t_data *stacks)
{
	action_add_first(&stacks->actions, "pb");
	if (stack_push(&stacks->a, &stacks->b))
	{
		stacks->size_a -= 1;
		stacks->size_b += 1;
		return (1);
	}
	return (0);
}
