/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:11:32 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:12:03 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "get_next_line.h"
#include "output.h"
#include "ft_printf.h"

static int	free_and_return(void *mem, int ret)
{
	free(mem);
	return (ret);
}

static int	print_msg_and_return(char *msg, int ret)
{
	ft_printf("%s\n", msg);
	return (ret);
}

static int	work_is_done(t_env *env)
{
	if (!env->stack_b && is_sort_stack(env->stack_a))
		return (print_msg_and_return("OK", 1));
	return (print_msg_and_return("KO", 1));
}

int			read_and_apply_instructions(t_env *env)
{
	char			*input;
	int				eol_had_newline;
	int				len;
	t_fct_to_apply	apply_fct;

	while ((len = get_next_line(0, &input, &eol_had_newline)) >= 0)
	{
		if (len > 3 || len < 2 || !input[len - 1] || !eol_had_newline)
			return (free_and_return((void *)input, 0));
		apply_fct = get_instruction_fct(input);
		if (!apply_fct)
			return (free_and_return((void *)input, 0));
		apply_fct(env, DONT_ADD_ACTION_LIST);
		if (VISUAL)
			print_env(env, input);
		free((void *)input);
	}
	return (work_is_done(env));
}
