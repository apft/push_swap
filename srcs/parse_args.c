/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:48:25 by apion             #+#    #+#             */
/*   Updated: 2019/04/23 13:26:22 by apion            ###   ########.fr       */
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

static void	jump_spaces(char **str)
{
	while (ft_isspace(**str))
		++(*str);
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
	jump_spaces(str);
	if (**str && !ft_isspace(**str))
		return (0);
	*n *= sign;
	return (1);
}

int			parse_args(int argc, char **argv, t_data *stacks)
{
	int		value;
	int		is_valid;

	while (--argc)
	{
		while (*argc[argv] && (is_valid = parse_args_atoi(&argv[argc], &value)))
			if (!stack_add_first(&stacks->b, value))
				return (0);
		if (!is_valid)
			return (0);
		while (stacks->b)
			if (!stack_push(&stacks->b, &stacks->a))
				return (0);
	}
	if (has_duplicate(stacks->a))
		return (0);
	return (1);
}
