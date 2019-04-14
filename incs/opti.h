/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:31:10 by apion             #+#    #+#             */
/*   Updated: 2019/04/14 13:07:26 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTI_H
# define OPTI_H

# include "utils.h"

# define MERGE_FROM_SB	1
# define MERGE_FROM_SA	0
# define MERGE_FROM_RB	1
# define MERGE_FROM_RA	0
# define MERGE_FROM_RRB	1
# define MERGE_FROM_RRA	0

int		is_last_action(t_action *actions, char *action);
int		do_opti_merge_sb_sa(t_data *stacks, int from_sb);
int		do_opti_merge_rb_ra(t_data *stacks, int from_rb);
int		do_opti_merge_rrb_rra(t_data *stacks, int from_rrb);

void	sort_three_elements(t_data *stacks);

#endif
