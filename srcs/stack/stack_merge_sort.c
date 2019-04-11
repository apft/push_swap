/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_merge_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:35:22 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 14:43:34 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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

void			stack_merge_sort(t_stack **head)
{
	t_stack	*left;
	t_stack *right;

	if (!head || !*head || !(*head)->next)
		return ;
	split_stack(*head, &left, &right);
	stack_merge_sort(&left);
	stack_merge_sort(&right);
	*head = sorted_merge(left, right);
}
