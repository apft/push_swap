/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:02:58 by apion             #+#    #+#             */
/*   Updated: 2019/04/03 18:05:27 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		pa(t_data *stacks)
{
	return (stack_push(&stacks->b, &stacks->a));
}

int		pb(t_data *stacks)
{
	return (stack_push(&stacks->a, &stacks->b));
}
