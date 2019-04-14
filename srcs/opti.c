/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:33:48 by apion             #+#    #+#             */
/*   Updated: 2019/04/14 13:06:28 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "core.h"

int		is_last_action(t_action *actions, char *action)
{
	return (actions && ft_strequ(actions->value, action));
}

int		do_opti_merge_sb_sa(t_data *stacks, int from_sb)
{
	if (from_sb)
		sb(stacks, DONT_ADD_ACTION_LIST);
	else
		sa(stacks, DONT_ADD_ACTION_LIST);
	stacks->actions->value[1] = 's';
	return (ss(stacks, DONT_ADD_ACTION_LIST));
}

int		do_opti_merge_rb_ra(t_data *stacks, int from_rb)
{
	if (from_rb)
		rrb(stacks, DONT_ADD_ACTION_LIST);
	else
		rra(stacks, DONT_ADD_ACTION_LIST);
	stacks->actions->value[1] = 'r';
	return (rr(stacks, DONT_ADD_ACTION_LIST));
}

int		do_opti_merge_rrb_rra(t_data *stacks, int from_rrb)
{
	if (from_rrb)
		rb(stacks, DONT_ADD_ACTION_LIST);
	else
		ra(stacks, DONT_ADD_ACTION_LIST);
	stacks->actions->value[2] = 'r';
	return (rrr(stacks, DONT_ADD_ACTION_LIST));
}
