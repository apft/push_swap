/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:02:58 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:14:08 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			pa(t_env *env, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&env->actions, "pa");
	if (stack_push(&env->stack_b, &env->stack_a))
	{
		env->size_a += 1;
		env->size_b -= 1;
		return (1);
	}
	return (0);
}

int			pb(t_env *env, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&env->actions, "pb");
	if (stack_push(&env->stack_a, &env->stack_b))
	{
		env->size_a -= 1;
		env->size_b += 1;
		return (1);
	}
	return (0);
}
