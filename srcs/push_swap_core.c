/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:28:11 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 13:14:31 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "output.h"
#include "ft_printf.h"

#define VISUAL	1

int			push_swap(t_data *stacks)
{
	if (VISUAL)
		print_stacks(stacks);
	action_add_first(&stacks->actions, "pb");
	if (VISUAL)
		action_print(stacks->actions);
	action_add_first(&stacks->actions, "sa");
	action_add_first(&stacks->actions, "ra");
	action_add_first(&stacks->actions, "pa");
	if (VISUAL)
		action_print(stacks->actions);
	return (1);
}
