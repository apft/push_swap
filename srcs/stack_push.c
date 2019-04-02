/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:45:03 by apion             #+#    #+#             */
/*   Updated: 2019/04/02 12:18:04 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

static t_stack	*create_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->value = value;
	node->next = 0;
	return (node);
}

int				stack_push(t_stack **head, int new_value)
{
	t_stack *new_node;

	if (!head)
		return (ERROR_STACK);
	new_node = create_node(new_value);
	if (!new_node)
		return (ERROR_STACK);
	if (*head)
		new_node->next = *head;
	*head = new_node;
	return (SUCCESS_STACK);
}
