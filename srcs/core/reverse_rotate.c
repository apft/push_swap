/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:07:15 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:15:21 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "opti.h"

int		rra(t_env *env, int add_to_actions)
{
	if (is_last_action(env->actions, "rrb"))
		return (do_opti_merge_rrb_rra(env, MERGE_FROM_RRB));
	if (add_to_actions)
		action_add_first(&env->actions, "rra");
	return (stack_reverse_rotate(&env->stack_a));
}

int		rrb(t_env *env, int add_to_actions)
{
	if (is_last_action(env->actions, "rra"))
		return (do_opti_merge_rrb_rra(env, MERGE_FROM_RRA));
	if (add_to_actions)
		action_add_first(&env->actions, "rrb");
	return (stack_reverse_rotate(&env->stack_b));
}

int		rrr(t_env *env, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&env->actions, "rrr");
	return (stack_reverse_rotate(&env->stack_a)
			+ stack_reverse_rotate(&env->stack_b));
}
