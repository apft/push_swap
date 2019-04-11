/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:30:25 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 14:32:53 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		size_stack(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		++size;
		stack = stack->next;
	}
	return (size);
}

int		size_action(t_action *action)
{
	int		size;

	size = 0;
	while (action)
	{
		++size;
		action = action->next;
	}
	return (size);
}
