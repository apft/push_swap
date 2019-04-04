/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:59:11 by apion             #+#    #+#             */
/*   Updated: 2019/04/04 10:40:58 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "ft_printf.h"

t_fct_to_apply	get_instruction_fct(char *input)
{
	int				size;
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

	size = sizeof(instructions) / sizeof(t_core);
	while (size--)
		if (ft_strequ(input, instructions[size].value))
			return (instructions[size].apply_fct);
	return (0);
}
