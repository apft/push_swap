/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:11:32 by apion             #+#    #+#             */
/*   Updated: 2019/04/03 19:15:11 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "get_next_line.h"
#include "output.h"
#include "ft_printf.h"

t_fct_to_apply	get_instruction_fct(char *input)
{
	static t_core	instructions[] = {
		{"sa", &sa},
		{"sb", &sb},
		{"ss", &ss},
		{"pa", &pa},
		{"pb", &pb},
		{"ra", &ra},
		{"rb", &rb},
		{"rr", &rr},
		{"rra", &rra},
		{"rrb", &rrb},
		{"rrr", &rrr}
	};
	int		size;

	size = sizeof(instructions) / sizeof(t_core);
	while (size--)
		if (ft_strequ(input, instructions[size].value))
			return (instructions[size].apply_fct);
	return (0);
}

int			read_and_apply_instructions(t_data *stacks)
{
	char			*input;
	int				eol_had_newline;
	int				status;
	t_fct_to_apply	apply_fct;

	print_stacks(stacks);
	while ((status = get_next_line(0, &input, &eol_had_newline)) >= 0)
	{
		if (!eol_had_newline)
			return (0);
		apply_fct = get_instruction_fct(input);
		if (!apply_fct)
			return (0);
		apply_fct(stacks);
		print_stacks(stacks);
	}
	ft_printf("status: %d\n", status);
	return (1);
}
