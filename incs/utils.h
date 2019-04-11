/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:49:58 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 13:07:45 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stack.h"
# include "actions.h"

typedef struct s_data	t_data;
struct	s_data
{
	t_stack		*a;
	t_stack		*b;
	t_action	*actions;
};

int			parse_args(int argc, char **argv, t_data *stacks);

int		free_stacks_and_return(t_data *stacks, int ret);
int		return_error_and_free_stacks(t_data *stacks);

#endif
