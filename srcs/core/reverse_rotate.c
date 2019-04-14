/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:07:15 by apion             #+#    #+#             */
/*   Updated: 2019/04/14 13:07:05 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "opti.h"

int		rra(t_data *stacks, int add_to_actions)
{
	if (is_last_action(stacks->actions, "rrb"))
		return (do_opti_merge_rrb_rra(stacks, MERGE_FROM_RRB));
	if (add_to_actions)
		action_add_first(&stacks->actions, "rra");
	return (stack_reverse_rotate(&stacks->a));
}

int		rrb(t_data *stacks, int add_to_actions)
{
	if (is_last_action(stacks->actions, "rra"))
		return (do_opti_merge_rrb_rra(stacks, MERGE_FROM_RRA));
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
