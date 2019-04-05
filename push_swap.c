/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:33:31 by apion             #+#    #+#             */
/*   Updated: 2019/04/05 13:23:47 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		main(int argc, char **argv)
{
	t_data	stacks;

	stacks.a = 0;
	stacks.b = 0;
	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &stacks))
		return (return_error_and_free_stacks(&stacks));
	return (free_stacks_and_return(&stacks, 0));
}
