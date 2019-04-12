/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:59:57 by apion             #+#    #+#             */
/*   Updated: 2019/04/12 20:02:15 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		sa(t_data *stacks, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&stacks->actions, "sa");
	return (stack_swap(stacks->a));
}

int		sb(t_data *stacks, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&stacks->actions, "sb");
	return (stack_swap(stacks->b));
}

int		ss(t_data *stacks, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&stacks->actions, "ss");
	return (stack_swap(stacks->a) + stack_swap(stacks->b));
}
