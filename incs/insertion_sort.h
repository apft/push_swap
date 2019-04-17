/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:09:36 by apion             #+#    #+#             */
/*   Updated: 2019/04/17 17:18:52 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERTION_SORT
# define INSERTION_SORT

# include "utils.h"

# define IS_STACK_A	1
# define IS_STACK_B	2

int		dst_to_top(int index, int size);
void	apply_rotation(t_data *stacks, int *dst_to_top, int which_stack);
void	insertion_sort(t_data *stacks);

#endif
