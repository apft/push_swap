/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:49:58 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:26:53 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stack.h"
# include "actions.h"

typedef struct s_env	t_env;
struct	s_env
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			size_a;
	int			size_b;
	t_action	*actions;
};

int		parse_args(int argc, char **argv, t_env *env);

int		is_sort_stack(t_stack *stack);
int		free_env_and_return(t_env *env, int ret);
int		return_error_and_free_env(t_env *env);

#endif
