/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:33:31 by apion             #+#    #+#             */
/*   Updated: 2019/04/04 13:37:17 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utils.h"
#include "checker.h"
void end (void) __attribute__((destructor));

int			parse_args(int argc, char **argv, t_data *stacks);

static int	free_and_return(t_data *stacks, int ret)
{
	stack_del_all(&stacks->a);
	stack_del_all(&stacks->b);
	return (ret);
}

static int	return_error_and_free(t_data *stacks)
{
	ft_dprintf(2, "Error\n");
	return (free_and_return(stacks, -1));
}

int		main(int argc, char **argv)
{
	t_data	stacks;

	stacks.a = 0;
	stacks.b = 0;
	if (argc < 2 || !parse_args(argc, argv, &stacks))
		return (return_error_and_free(&stacks));
	ft_printf("stack a:");
	stack_print(stacks.a);
	ft_printf("\n");
	if (!read_and_apply_instructions(&stacks))
		return (return_error_and_free(&stacks));
	return (free_and_return(&stacks, 0));
}

void end (void)
{
	  ft_printf ("\nIn end ()\n");
}
