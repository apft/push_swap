/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:20:46 by apion             #+#    #+#             */
/*   Updated: 2019/04/05 13:23:13 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

int		free_stacks_and_return(t_data *stacks, int ret)
{
	stack_del_all(&stacks->a);
	stack_del_all(&stacks->b);
	return (ret);
}

int		return_error_and_free_stacks(t_data *stacks)
{
	ft_dprintf(2, "Error\n");
	return (free_stacks_and_return(stacks, -1));
}
