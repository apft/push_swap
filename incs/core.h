/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:08:31 by apion             #+#    #+#             */
/*   Updated: 2019/04/03 19:12:59 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "utils.h"

# define N_INSTRUCTIONS	11

int				pa(t_data *stacks);
int				pb(t_data *stacks);
int				rra(t_data *stacks);
int				rrb(t_data *stacks);
int				rrr(t_data *stacks);
int				ra(t_data *stacks);
int				rb(t_data *stacks);
int				rr(t_data *stacks);
int				sa(t_data *stacks);
int				sb(t_data *stacks);
int				ss(t_data *stacks);

typedef struct s_core	t_core;
struct			s_core
{
	char	*value;
	int		(*apply_fct)(t_data *);
};

typedef int		(*t_fct_to_apply)(t_data *);

t_fct_to_apply	get_instruction_fct(char *input);

#endif
