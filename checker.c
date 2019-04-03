/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:33:31 by apion             #+#    #+#             */
/*   Updated: 2019/04/03 12:08:31 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utils.h"
int			parse_args(int argc, char **argv, t_data *stacks);

int		main(int argc, char **argv)
{
	t_data	stacks;

	stacks.a = 0;
	stacks.b = 0;
	if (argc < 2 || !parse_args(argc, argv, &stacks))
	{
		ft_dprintf(2, "Error\n");
		return (-1);
	}
	stack_print(stacks.a);
	ft_printf("\nrotate:");
	stack_rotate(&stacks.a);
	stack_print(stacks.a);
	ft_printf("\nreverse rotate:");
	stack_reverse_rotate(&stacks.a);
	stack_print(stacks.a);
	ft_printf("\ndel 1st:");
	stack_del_first(&stacks.a);
	stack_print(stacks.a);
	ft_printf("\ndel all:");
	stack_del_all(&stacks.a);
	stack_print(stacks.a);
	return (0);
}
