/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:24:15 by apion             #+#    #+#             */
/*   Updated: 2019/04/04 13:27:46 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack		*stack_dup(t_stack *from)
{
	t_stack	*copy;

	copy = 0;
	while (from)
	{
		stack_add_first(&copy, from->value);
		from = from->next;
	}
	return (copy);
}
