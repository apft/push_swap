/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:18:02 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 15:11:03 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

int		has_duplicate(t_stack *stack)
{
	t_stack *copy_head;
	t_stack *copy;
	int		has_duplicate;

	copy_head = stack_dup(stack);
	stack_merge_sort(&copy_head);
	copy = copy_head;
	has_duplicate = 0;
	while (!has_duplicate && copy && copy->next)
	{
		if (copy->value == copy->next->value)
			has_duplicate = 1;
		copy = copy->next;
	}
	stack_del_all(&copy_head);
	return (has_duplicate);
}

int		get_median(t_stack *stack)
{
	int		middle;
	int		median;
	t_stack	*copy_head;
	t_stack	*copy;

	if (!stack)
		return (0);
	copy_head = stack_dup(stack);
	stack_merge_sort(&copy_head);
	copy = copy_head;
	middle = size_stack(copy_head) / 2;
	while (middle-- && copy->next)
		copy = copy->next;
	median = copy->value;
	stack_del_all(&copy_head);
	return (median);
}
