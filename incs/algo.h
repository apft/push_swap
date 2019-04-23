/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <pion@student.42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:59:19 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:03:20 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "utils.h"

int		dst_to_top(int index, int size);
int		n_actions_to_pa(int index_b, int index_a, t_env *env);
void	apply_action_n_times(t_env *env, int n, int (*fct)(t_env *, int));
void	do_actions(t_env *env, int dst_b, int dst_a);

#endif
