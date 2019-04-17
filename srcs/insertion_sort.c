/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <pion@student.42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:16:20 by apion             #+#    #+#             */
/*   Updated: 2019/04/17 13:46:59 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "ft_printf.h"

//static int	dst_to_top(int index, int size)
//{
//	if (index <= size / 2)
//		return (index);
//	return (-(size - index));
//}

static int	search_next_a(t_stack *stack_a, int value_b, int *index_next)
{
	int		next;

	next = stack_a ? stack_a->value : 0;
	*index_next = 0;
	while (stack_a)
	{
		if (stack_a->value > value_b && stack_a->value < next)
			next = stack_a->value;
		++(*index_next);
		stack_a = stack_a->next;
	}
	return (next);
}

static int	search_best_b(t_data *stacks, int *next_a, int *next_a_index, int *best_b_index)
{
	t_stack	*stack_b;
	int		best_b;
	int		tmp_next;
	int		tmp_next_index;

	stack_b = stacks->b;
	best_b = stack_b->value;
	*best_b_index = 0;
	while (stack_b)
	{
		tmp_next = search_next_a(stacks->a, stack_b->value, &tmp_next_index);
		if (tmp_next_index < *next_a_index)
		{
			*next_a = tmp_next;
			*next_a_index = tmp_next_index;
			best_b = stack_b->value;
		}
		++(*best_b_index);
		stack_b = stack_b->next;
	}
	return (best_b);
}

void		insertion_sort(t_data *stacks)
{
	int		best_b;
	int		best_b_index;
	int		next_a;
	int		next_a_index;

	if (!stacks->a)
		return ;
	next_a = stacks->a->value;
	next_a_index = 0;
	while (stacks->b)
	{
		best_b = search_best_b(stacks, &next_a, &next_a_index, &best_b_index);
		ft_printf("best_b: %3d   %d\n", best_b_index, best_b);
	}
}
