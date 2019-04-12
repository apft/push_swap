/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:07:15 by apion             #+#    #+#             */
/*   Updated: 2019/04/12 20:00:40 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		rra(t_data *stacks, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&stacks->actions, "rra");
	return (stack_reverse_rotate(&stacks->a));
}

int		rrb(t_data *stacks, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&stacks->actions, "rrb");
	return (stack_reverse_rotate(&stacks->b));
}

int		rrr(t_data *stacks, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&stacks->actions, "rrr");
	return (stack_reverse_rotate(&stacks->a)
			+ stack_reverse_rotate(&stacks->b));
}
