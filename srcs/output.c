/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:51:22 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 18:03:06 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

#define WIDTH_COLUMN	14

static void	print_header(void)
{
	ft_printf("%y%{u}%*s%*s | %*s%*s%{\\u}\n",
			WIDTH_COLUMN / 2, "A", WIDTH_COLUMN / 2, "",
			WIDTH_COLUMN / 2, "B", WIDTH_COLUMN / 2, "");
}

static void	print_node(t_stack *node)
{
	if (node)
		ft_printf("%*d", WIDTH_COLUMN, node->value);
	else
		ft_printf("%*s", WIDTH_COLUMN, " ");
}

void		print_stacks(t_data *stacks)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stacks->a;
	stack_b = stacks->b;
	print_header();
	while (stack_a || stack_b)
	{
		print_node(stack_a);
		if (stack_a)
			stack_a = stack_a->next;
		ft_printf(" | ");
		print_node(stack_b);
		if (stack_b)
			stack_b = stack_b->next;
		ft_printf("\n");
	}
}
