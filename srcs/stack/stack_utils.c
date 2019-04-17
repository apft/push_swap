/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:18:02 by apion             #+#    #+#             */
/*   Updated: 2019/04/17 17:45:56 by apion            ###   ########.fr       */
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

int		stack_get_median(t_stack *stack)
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

void	compute_scale_values(t_stack *stack)
{
	t_stack	*stack_sort_head;
	t_stack	*stack_sort;
	t_stack	*copy;
	int		index;

	stack_sort_head = stack_dup(stack);
	stack_merge_sort(&stack_sort_head);
	stack_sort = stack_sort_head;
	index = 0;
	while (stack_sort)
	{
		copy = stack;
		while (copy && copy->value != stack_sort->value)
			copy = copy->next;
		copy->index = index++;
		stack_sort = stack_sort->next;
	}
	stack_del_all(&stack_sort_head);
}
