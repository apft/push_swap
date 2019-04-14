/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:59:57 by apion             #+#    #+#             */
/*   Updated: 2019/04/13 18:44:54 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "opti.h"

int		ss(t_data *stacks, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&stacks->actions, "ss");
	return (stack_swap(stacks->a) + stack_swap(stacks->b));
}

int		sa(t_data *stacks, int add_to_actions)
{
	if (is_last_action(stacks->actions, "sb"))
		return (do_opti_merge_sb_sa(stacks, MERGE_FROM_SB));
	if (stacks->b && stacks->b->next
		&& stacks->b->value < stacks->b->next->value)
		return (ss(stacks, add_to_actions));
	if (add_to_actions)
		action_add_first(&stacks->actions, "sa");
	return (stack_swap(stacks->a));
}

int		sb(t_data *stacks, int add_to_actions)
{
	if (is_last_action(stacks->actions, "sa"))
		return (do_opti_merge_sb_sa(stacks, MERGE_FROM_SA));
	if (stacks->a && stacks->a->next
		&& stacks->a->value > stacks->a->next->value)
		return (ss(stacks, add_to_actions));
	if (add_to_actions)
		action_add_first(&stacks->actions, "sb");
	return (stack_swap(stacks->b));
}
