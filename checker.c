/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:33:31 by apion             #+#    #+#             */
/*   Updated: 2019/04/02 14:31:36 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "stack.h"

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		is_valid_arg;

	stack_a = 0;
	stack_b = 0;
	while (--argc && (is_valid_arg = ft_is_valid_atoi_input(argv[argc])))
		stack_push(&stack_a, ft_atoi(argv[argc]));
	if (!is_valid_arg)
	{
		ft_printf("Error\n");
		return (-1);
	}
	stack_print(stack_a);
	ft_printf("\nrotate:");
	stack_rotate(&stack_a);
	stack_print(stack_a);
	ft_printf("\nreverse rotate:");
	stack_reverse_rotate(&stack_a);
	stack_print(stack_a);
	ft_printf("\ndel 1st:");
	stack_del_first(&stack_a);
	stack_print(stack_a);
	ft_printf("\ndel all:");
	stack_del_all(&stack_a);
	stack_print(stack_a);
	return (0);
}
