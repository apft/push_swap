/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:30:22 by apion             #+#    #+#             */
/*   Updated: 2019/04/02 12:51:27 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_rotate(t_stack **head)
{
	t_stack	*first_node;
	t_stack *last_node;

	if (!head || !*head || !((*head)->next))
		return (ERROR_STACK);
	first_node = *head;
	*head = first_node->next;
	last_node = *head;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = first_node;
	first_node->next = 0;
	return (SUCCESS_STACK);
}

int		stack_reverse_rotate(t_stack **head)
{
	t_stack	*first_node;
	t_stack	*penultimate_node;
	t_stack	*last_node;

	if (!head || !*head || !((*head)->next))
		return (ERROR_STACK);
	first_node = *head;
	penultimate_node = *head;
	while (penultimate_node->next && penultimate_node->next->next)
		penultimate_node = penultimate_node->next;
	if (penultimate_node->next)
		last_node = penultimate_node->next;
	else
		last_node = penultimate_node;
	*head = last_node;
	last_node->next = first_node;
	penultimate_node->next = 0;
	return (SUCCESS_STACK);
}
