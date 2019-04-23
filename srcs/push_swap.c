/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:33:31 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 20:09:41 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

int		main(int argc, char **argv)
{
	static t_env	env;

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &env))
		return (return_error_and_free_env(&env));
	push_swap(&env);
	return (free_env_and_return(&env, 0));
}
