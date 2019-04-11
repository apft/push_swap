/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:20:46 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 13:27:27 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

int		is_sort_stack(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value >= stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		free_stacks_and_return(t_data *stacks, int ret)
{
	stack_del_all(&stacks->a);
	stack_del_all(&stacks->b);
	action_del_all(&stacks->actions);
	return (ret);
}

int		return_error_and_free_stacks(t_data *stacks)
{
	ft_dprintf(2, "Error\n");
	return (free_stacks_and_return(stacks, -1));
}
