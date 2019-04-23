/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:59:57 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:18:35 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "opti.h"

int		ss(t_env *env, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&env->actions, "ss");
	return (stack_swap(env->stack_a) + stack_swap(env->stack_b));
}

int		sa(t_env *env, int add_to_actions)
{
	if (is_last_action(env->actions, "sb"))
		return (do_opti_merge_sb_sa(env, MERGE_FROM_SB));
	if (env->stack_b && env->stack_b->next
		&& env->stack_b->value < env->stack_b->next->value)
		return (ss(env, add_to_actions));
	if (add_to_actions)
		action_add_first(&env->actions, "sa");
	return (stack_swap(env->stack_a));
}

int		sb(t_env *env, int add_to_actions)
{
	if (is_last_action(env->actions, "sa"))
		return (do_opti_merge_sb_sa(env, MERGE_FROM_SA));
	if (env->stack_a && env->stack_a->next
		&& env->stack_a->value > env->stack_a->next->value)
		return (ss(env, add_to_actions));
	if (add_to_actions)
		action_add_first(&env->actions, "sb");
	return (stack_swap(env->stack_b));
}
