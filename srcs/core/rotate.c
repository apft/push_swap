/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:05:39 by apion             #+#    #+#             */
/*   Updated: 2019/04/12 20:07:05 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ra(t_data *stacks, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&stacks->actions, "ra");
	return (stack_rotate(&stacks->a));
}

int		rb(t_data *stacks, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&stacks->actions, "rb");
	return (stack_rotate(&stacks->b));
}

int		rr(t_data *stacks, int add_to_actions)
{
	if (add_to_actions)
		action_add_first(&stacks->actions, "rr");
	return (stack_rotate(&stacks->a) + stack_rotate(&stacks->b));
}
