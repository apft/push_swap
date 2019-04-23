/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:33:31 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 19:12:12 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "checker.h"

int		main(int argc, char **argv)
{
	static t_data	stacks;

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &stacks))
		return (return_error_and_free_stacks(&stacks));
	if (!read_and_apply_instructions(&stacks))
		return (return_error_and_free_stacks(&stacks));
	return (free_stacks_and_return(&stacks, 0));
}
