/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:20:46 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:08:53 by apion            ###   ########.fr       */
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

int		free_env_and_return(t_env *env, int ret)
{
	stack_del_all(&env->stack_a);
	stack_del_all(&env->stack_b);
	action_del_all(&env->actions);
	return (ret);
}

int		return_error_and_free_env(t_env *env)
{
	ft_dprintf(2, "Error\n");
	return (free_env_and_return(env, -1));
}
