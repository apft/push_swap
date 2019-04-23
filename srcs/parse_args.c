/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:48:25 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 19:57:05 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "core.h"
#include "libft.h"
#include "ft_printf.h"

#define INT_LEN_MAX 10
#ifndef INT_MIN
# define INT_MIN -2147483648
#endif

static int	jump_spaces(char **str)
{
	int		has_jumped;

	has_jumped = 0;
	while (ft_isspace(**str) && (has_jumped = 1))
		++(*str);
	return (has_jumped);
}

static int	is_valid_str(char *str)
{
	if (ft_isdigit(*str) || ft_isspace(*str))
		return (1);
	if (ft_issign(*str) && ft_isdigit(*(str + 1)))
		return (1);
	return (0);
}

static int	parse_args_atoi(char **str, int *n)
{
	int		sign;

	*n = 0;
	sign = 1;
	jump_spaces(str);
	if (!**str)
		return (0);
	if (**str == '+' || **str == '-')
		sign = *((*str)++) == '-' ? -1 : 1;
	if (!**str || (**str && !is_valid_str(*str)))
		return (0);
	while (ft_isdigit(**str))
	{
		*n = 10 * (*n) + (*((*str)++) - '0');
		if ((*n < 0 && *n != INT_MIN) || (sign > 0 && *n == INT_MIN))
			return (0);
	}
	if ((**str && !ft_isspace(**str))
			|| (jump_spaces(str) && **str && !is_valid_str(*str)))
		return (0);
	*n *= sign;
	return (1);
}

int			parse_args(int argc, char **argv, t_data *stacks)
{
	int		i;
	int		value;
	int		is_valid;

	i = 0;
	while (++i < argc)
	{
		while (*argv[i] && (is_valid = parse_args_atoi(&argv[i], &value)))
			if (!stack_add_first(&stacks->a, value))
				return (0);
		if (!is_valid)
			return (0);
	}
	if (has_duplicate(stacks->a))
		return (0);
	stack_reverse(&stacks->a);
	return (1);
}
