/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:33:48 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:21:52 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "core.h"

int		is_last_action(t_action *actions, char *action)
{
	return (actions && ft_strequ(actions->value, action));
}

int		do_opti_merge_sb_sa(t_env *env, int from_sb)
{
	if (from_sb)
		sb(env, DONT_ADD_ACTION_LIST);
	else
		sa(env, DONT_ADD_ACTION_LIST);
	env->actions->value[1] = 's';
	return (ss(env, DONT_ADD_ACTION_LIST));
}

int		do_opti_merge_rb_ra(t_env *env, int from_rb)
{
	if (from_rb)
		rrb(env, DONT_ADD_ACTION_LIST);
	else
		rra(env, DONT_ADD_ACTION_LIST);
	env->actions->value[1] = 'r';
	return (rr(env, DONT_ADD_ACTION_LIST));
}

int		do_opti_merge_rrb_rra(t_env *env, int from_rrb)
{
	if (from_rrb)
		rb(env, DONT_ADD_ACTION_LIST);
	else
		ra(env, DONT_ADD_ACTION_LIST);
	env->actions->value[2] = 'r';
	return (rrr(env, DONT_ADD_ACTION_LIST));
}
