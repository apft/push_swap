/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:49:58 by apion             #+#    #+#             */
/*   Updated: 2019/04/05 13:24:01 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stack.h"

typedef struct s_data	t_data;
struct	s_data
{
	t_stack	*a;
	t_stack	*b;
};

int			parse_args(int argc, char **argv, t_data *stacks);

int		free_stacks_and_return(t_data *stacks, int ret);
int		return_error_and_free_stacks(t_data *stacks);

#endif
