/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:11:32 by apion             #+#    #+#             */
/*   Updated: 2019/04/04 10:42:49 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "get_next_line.h"
#include "output.h"
#include "ft_printf.h"

static int	print_msg_and_return(char *msg, int ret)
{
	ft_printf("%s\n", msg);
	return (ret);
}

/*
** Need to check for duplicate before is_sort
**  - if stack_b is not empty => return `KO'
**  - if stack_a[i] > stack_a[i+1] => return `KO'
**  - if stack_a[i] == stack_a[i+1] => return `Error'
**  - if stack_a not sorted, there might still exists some duplicate values...
**  	and this information is hidden without a check of all the given args
*/

static int	work_is_done(t_data *stacks)
{
	if (stacks->b)
		return (print_msg_and_return("KO", 1));
	else if (stacks->a)
		return (print_msg_and_return("OK", 1));
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
	return (work_is_done(stacks));
}
