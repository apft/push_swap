/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:55:46 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 19:56:30 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		stack_reverse(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!head || !*head)
		return ;
	prev = 0;
	while ((*head)->next)
	{
		tmp = (*head)->next;
		(*head)->next = prev;
		prev = (*head);
		*head = tmp;
	}
	(*head)->next = prev;
}
