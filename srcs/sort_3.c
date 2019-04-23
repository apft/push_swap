/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:47:42 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:22:36 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "opti.h"

void	sort_three_elements(t_env *env)
{
	int		a;
	int		b;
	int		c;

	if (env->size_a != 3)
		return ;
	a = env->stack_a->value;
	b = env->stack_a->next->value;
	c = env->stack_a->next->next->value;
	if (a < b && b < c)
		return ;
	else if (b < c && c < a)
		ra(env, ADD_ACTION_LIST);
	else if (c < a && a < b)
		rra(env, ADD_ACTION_LIST);
	else
	{
		if (is_last_action(env->actions, "sb"))
			do_opti_merge_sb_sa(env, MERGE_FROM_SB);
		else
			sa(env, ADD_ACTION_LIST);
		sort_three_elements(env);
	}
}
