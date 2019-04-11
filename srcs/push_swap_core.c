/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:28:11 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 16:26:20 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "output.h"
#include "ft_printf.h"

#define VISUAL	0

void	insert_b(t_data *stacks, int value)
{
	//ft_printf("value = %d, median_b = %d\n", value, stacks->median_b);
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
	int		median_a;

	if (VISUAL)
		print_stacks(stacks);
	//ft_printf("med_a = %d\n", median_a);
	while (!is_sort_stack(stacks->a))
	{
		count = 0;
		size_a = size_stack(stacks->a);
		median_a = get_median(stacks->a);
		stacks->median_a = median_a;
		stacks->median_b = 0;
		while (!is_sort_stack(stacks->a) && count++ < size_a)
		{
			if (stacks->a->value >= median_a)
				ra(stacks);
			else
				insert_b(stacks, stacks->a->value);
		}
	}
	if (!is_sort_stack(stacks->a))
	{
		if (VISUAL)
			print_stacks(stacks);
		//ft_printf("NOT SORTED!!!\n");
	}
	if (VISUAL)
		print_stacks(stacks);
	if (size_stack(stacks->a) == 1 && stacks->b)
	{
		pb(stacks);
		if (!is_sort_stack(stacks->a))
			ra(stacks);
	}
	while (stacks->b)
		insert_back_in_a(stacks);

	if (VISUAL)
		print_stacks(stacks);
	//ft_printf("med_a = %d, med_b = %d\n", stacks->median_a, stacks->median_b);
	action_print(stacks->actions);
	return (1);
}
