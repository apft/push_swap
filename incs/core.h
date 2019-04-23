/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:08:31 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:04:50 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "utils.h"

# define ADD_ACTION_LIST		1
# define DONT_ADD_ACTION_LIST	0

int				pa(t_env *env, int add_to_action_list);
int				pb(t_env *env, int add_to_action_list);
int				rra(t_env *env, int add_to_action_list);
int				rrb(t_env *env, int add_to_action_list);
int				rrr(t_env *env, int add_to_action_list);
int				ra(t_env *env, int add_to_action_list);
int				rb(t_env *env, int add_to_action_list);
int				rr(t_env *env, int add_to_action_list);
int				sa(t_env *env, int add_to_action_list);
int				sb(t_env *env, int add_to_action_list);
int				ss(t_env *env, int add_to_action_list);

typedef struct s_core	t_core;
struct			s_core
{
	char	*value;
	int		(*apply_fct)(t_env *, int);
};

typedef int		(*t_fct_to_apply)(t_env *, int);

t_fct_to_apply	get_instruction_fct(char *input);

#endif
