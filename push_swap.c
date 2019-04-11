/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:33:31 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 13:20:28 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
int		push_swap(t_data *stacks);
int		main(int argc, char **argv)
{
	static t_data	stacks;

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &stacks))
		return (return_error_and_free_stacks(&stacks));
	push_swap(&stacks);
	return (free_stacks_and_return(&stacks, 0));
}
