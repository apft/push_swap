/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:45:01 by apion             #+#    #+#             */
/*   Updated: 2019/04/02 12:22:53 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

int			stack_del_first(t_stack **head)
{
	t_stack	*temp;

	if (!head || !*head)
		return (EMPTY_STACK);
	temp = *head;
	*head = temp->next;
	free(temp);
	return (*head ? SUCCESS_STACK : EMPTY_STACK);
}

int			stack_del_all(t_stack **head)
{
	if (!head || !*head)
		return (EMPTY_STACK);
	while (stack_del_first(head) != EMPTY_STACK)
		;
	return (EMPTY_STACK);
}
