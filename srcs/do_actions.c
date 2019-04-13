/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <pion@student.42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:57:37 by apion             #+#    #+#             */
/*   Updated: 2019/04/13 15:06:45 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "core.h"
#include "libft.h"

void	apply_action_n_times(t_data *stacks, int n, int (*fct)(t_data *, int))
{
	while (n--)
		fct(stacks, ADD_ACTION_LIST);
}

void	do_actions(t_data *stacks, int dst_b, int dst_a)
{
	if (dst_a == dst_b)
		apply_action_n_times(stacks, dst_a, (dst_a < 0 ? &rrr : &rr));
	else if (dst_a > 0 && dst_b > 0)
	{
		apply_action_n_times(stacks, ft_min(dst_a, dst_b), &rr);
		apply_action_n_times(stacks, ft_abs(dst_a - dst_b), dst_a < dst_b ? &rrb : &rra);
	}
	else if (dst_a < 0 && dst_b < 0)
	{
		apply_action_n_times(stacks, ft_min(-dst_a, -dst_b), &rrr);
		apply_action_n_times(stacks, ft_abs(dst_a - dst_b), dst_a < dst_b ? &rra : &rrb);
	}
	else
	{
		apply_action_n_times(stacks, ft_abs(dst_a), (dst_a < 0 ? &rra : &ra));
		apply_action_n_times(stacks, ft_abs(dst_b), (dst_b < 0 ? &rrb : &rb));
	}
	pa(stacks, ADD_ACTION_LIST);
}
