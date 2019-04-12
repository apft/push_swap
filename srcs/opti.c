/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:33:48 by apion             #+#    #+#             */
/*   Updated: 2019/04/12 20:38:14 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "core.h"

int		is_last_action(t_action *actions, char *action)
{
	return (actions && ft_strequ(actions->value, action));
}

void	do_opti_merge_rb_ra(t_data *stacks, int from_rb)
{
	if (from_rb)
		rrb(stacks, DONT_ADD_ACTION_LIST);
	else
		rra(stacks, DONT_ADD_ACTION_LIST);
	rr(stacks, DONT_ADD_ACTION_LIST);
	stacks->actions->value[1] = 'r';
}

void	do_opti_merge_sb_sa(t_data *stacks, int from_sb)
{
	if (from_sb)
		sb(stacks, DONT_ADD_ACTION_LIST);
	else
		sa(stacks, DONT_ADD_ACTION_LIST);
	ss(stacks, DONT_ADD_ACTION_LIST);
	stacks->actions->value[0] = 's';
	stacks->actions->value[1] = 's';
}
