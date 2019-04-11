/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:28:11 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 15:45:35 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "output.h"
#include "ft_printf.h"

#define VISUAL	1

void	insert_b(t_data *stacks, int value)
{
	ft_printf("value = %d, median_b = %d\n", value, stacks->median_b);
	pb(stacks);
	if (value < stacks->median_b)
		rb(stacks);
}

void	insert_back_in_a(t_data *stacks)
{
	int		rotation_count;

	rotation_count = 0;
	while (stacks->a->value < stacks->b->value)
	{
		ra(stacks);
		++rotation_count;
	}
	pa(stacks);
	while (rotation_count--)
		rra(stacks);
}

int			push_swap(t_data *stacks)
{
	int		count;
	int		size_a;

	count = 0;
	size_a = size_stack(stacks->a);
	stacks->median_a = get_median(stacks->a);
	stacks->median_b = 0;
	ft_printf("med_a = %d\n", stacks->median_a);
	while (!is_sort_stack(stacks->a) && count++ < size_a)
	{
		if (stacks->a->value >= stacks->median_a)
			ra(stacks);
		else
			insert_b(stacks, stacks->a->value);
	}
	if (VISUAL)
		print_stacks(stacks);
	if (!is_sort_stack(stacks->a))
	{
		ft_printf("NOT SORTED!!!\n");
	}
	while (!is_sort_stack(stacks->a))
		insert_b(stacks, stacks->a->value);
	while (stacks->b)
		insert_back_in_a(stacks);

	if (VISUAL)
		print_stacks(stacks);
	ft_printf("med_a = %d, med_b = %d\n", stacks->median_a, stacks->median_b);
	action_print(stacks->actions);
	return (1);
}
