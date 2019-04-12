/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:45:06 by apion             #+#    #+#             */
/*   Updated: 2019/04/12 19:37:42 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_swap(t_stack *head)
{
	if (!head || !(head->next))
		return (0);
	head->value ^= head->next->value;
	head->next->value ^= head->value;
	head->value ^= head->next->value;
	head->index ^= head->next->index;
	head->next->index ^= head->index;
	head->index ^= head->next->index;
	return (1);
}
