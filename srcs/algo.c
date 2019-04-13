/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <pion@student.42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:00:21 by apion             #+#    #+#             */
/*   Updated: 2019/04/13 15:05:07 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

int		dst_to_top(int index, int size)
{
	if (index <= size / 2)
		return (index);
	return (-(size - index));
}

int		n_actions_to_pa(int index_b, int index_a, t_data *stacks)
{
	int		dst_a;
	int		dst_b;

	dst_a = dst_to_top(index_a, stacks->size_a);
	dst_b = dst_to_top(index_b, stacks->size_b);
	if (dst_a == dst_b)
		return (ft_abs(dst_a));
	if ((dst_a < 0 && dst_b < 0) || (dst_a > 0 && dst_b > 0))
		return (ft_max(ft_abs(dst_a), ft_abs(dst_b)));
	return (ft_abs(dst_a) + ft_abs(dst_b));
}
