/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:05:39 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:16:24 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "opti.h"

int		ra(t_env *env, int add_to_actions)
{
	if (is_last_action(env->actions, "rb"))
		return (do_opti_merge_rb_ra(env, MERGE_FROM_RB));
	if (add_to_actions)
		action_add_first(&env->actions, "ra");
	return (stack_rotate(&env->stack_a));
}

int		rb(t_env *env, int add_to_actions)
{
	if (is_last_action(env->actions, "ra"))
		return (do_opti_merge_rb_ra(env, MERGE_FROM_RA));
	if (add_to_actions)
		action_add_first(&env->actions, "rb");
	return (stack_rotate(&env->stack_b));
}

int		rr(t_env *env, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&env->actions, "rr");
	return (stack_rotate(&env->stack_a) + stack_rotate(&env->stack_b));
}
