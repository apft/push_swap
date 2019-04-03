/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:37:48 by apion             #+#    #+#             */
/*   Updated: 2019/04/03 15:22:23 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*node;

	if (!stack_from || !stack_to || !*stack_from)
		return (0);
	node = *stack_from;
	*stack_from = node->next;
	node->next = *stack_to;
	*stack_to = node;
	return (1);
}
