/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:18:02 by apion             #+#    #+#             */
/*   Updated: 2019/04/04 13:32:57 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

static void		split_stack(t_stack *head, t_stack **left, t_stack **right)
{
	t_stack	*slow;
	t_stack	*fast;

	if (!head || !left || !right)
		return ;
	slow = head;
	fast = head->next;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	*left = head;
	*right = slow->next;
	slow->next = 0;
}

static t_stack	*min_node(t_stack *a, t_stack *b)
{
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (a->value < b->value)
		return (a);
	return (b);
}

static t_stack	*sorted_merge(t_stack *left, t_stack *right)
{
	t_stack *result;

	if (!left || !right)
		return (min_node(left, right));
	if (left->value <= right->value)
	{
		result = left;
		result->next = sorted_merge(left->next, right);
	}
	else
	{
		result = right;
		result->next = sorted_merge(right->next, left);
	}
	return (result);
}

static void	merge_sort(t_stack **head)
{
	t_stack	*left;
	t_stack *right;

	if (!head || !*head || !(*head)->next)
		return ;
	split_stack(*head, &left, &right);
	merge_sort(&left);
	merge_sort(&right);
	*head = sorted_merge(left, right);
}

int		has_duplicate(t_stack *stack)
{
	t_stack *copy_head;
	t_stack *copy;
	int		has_duplicate;

	copy_head = stack_dup(stack);
	merge_sort(&copy_head);
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
