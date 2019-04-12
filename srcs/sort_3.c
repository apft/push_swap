/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:47:42 by apion             #+#    #+#             */
/*   Updated: 2019/04/12 19:46:45 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "output.h"

void	sort_three_elements(t_data *stacks)
{
	int		a;
	int		b;
	int		c;

	if (stacks->size_a != 3)
		return ;
	a = stacks->a->value;
	b = stacks->a->next->value;
	c = stacks->a->next->next->value;
	if (a < b && b < c)
		return ;
	else if (b < c && c < a)
		ra(stacks);
	else if (c < a && a < b)
		rra(stacks);
	else
	{
		sa(stacks);
		sort_three_elements(stacks);
	}
}
