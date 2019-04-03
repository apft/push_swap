/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:59:57 by apion             #+#    #+#             */
/*   Updated: 2019/04/03 18:03:21 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		sa(t_data *stacks)
{
	return (stack_swap(stacks->a));
}

int		sb(t_data *stacks)
{
	return (stack_swap(stacks->b));
}

int		ss(t_data *stacks)
{
	return (stack_swap(stacks->a) + stack_swap(stacks->b));
}
