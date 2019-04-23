/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:51:22 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:13:05 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

#define CLEAR_SCREEN	1

#define WIDTH_NUMBER	7
#define GROUP_SIZE		6
#define WIDTH_COLUMN	(GROUP_SIZE * WIDTH_NUMBER)

static void		print_header(char *action)
{
	if (CLEAR_SCREEN)
		ft_printf("%y");
	ft_printf("Stacks state after: %{cyan}%s%{nc}\n", action);
	ft_printf("%{u}%*s%*s | %*s%*s%{\\u}\n",
			WIDTH_COLUMN / 2, "A", WIDTH_COLUMN / 2, "",
			WIDTH_COLUMN / 2, "B", WIDTH_COLUMN / 2, "");
}

static void		print_node(t_stack *node)
{
	if (node)
		ft_printf("%*d", WIDTH_NUMBER, node->value);
	else
		ft_printf("%*s", WIDTH_NUMBER, " ");
}

static t_stack	*print_group(t_stack *stack)
{
	int		group_size;

	group_size = GROUP_SIZE;
	while (group_size--)
	{
		print_node(stack);
		if (stack)
			stack = stack->next;
	}
	return (stack);
}

void			print_env(t_env *env, char *action)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = env->stack_a;
	stack_b = env->stack_b;
	print_header(action);
	while (stack_a || stack_b)
	{
		stack_a = print_group(stack_a);
		ft_printf(" | ");
		stack_b = print_group(stack_b);
		ft_printf("\n");
	}
}
