/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:08:31 by apion             #+#    #+#             */
/*   Updated: 2019/04/12 20:06:40 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "utils.h"

# define ADD_ACTION_LIST		1
# define DONT_ADD_ACTION_LIST	0

int				pa(t_data *stacks, int add_to_action_list);
int				pb(t_data *stacks, int add_to_action_list);
int				rra(t_data *stacks, int add_to_action_list);
int				rrb(t_data *stacks, int add_to_action_list);
int				rrr(t_data *stacks, int add_to_action_list);
int				ra(t_data *stacks, int add_to_action_list);
int				rb(t_data *stacks, int add_to_action_list);
int				rr(t_data *stacks, int add_to_action_list);
int				sa(t_data *stacks, int add_to_action_list);
int				sb(t_data *stacks, int add_to_action_list);
int				ss(t_data *stacks, int add_to_action_list);

typedef struct s_core	t_core;
struct			s_core
{
	char	*value;
	int		(*apply_fct)(t_data *, int);
};

typedef int		(*t_fct_to_apply)(t_data *, int);

t_fct_to_apply	get_instruction_fct(char *input);

#endif
