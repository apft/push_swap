/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:05:03 by apion             #+#    #+#             */
/*   Updated: 2019/04/02 12:18:30 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

void		stack_print(t_stack *node)
{
	while (node)
	{
		ft_printf(" %d ", node->value);
		node = node->next;
	}
}
