/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:48:25 by apion             #+#    #+#             */
/*   Updated: 2019/04/03 15:20:03 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "stack.h"
#include "libft.h"
#include "ft_printf.h"

#define INT_LEN_MAX 10
#define INT_MAX_STR "2147483647"
#define INT_MIN_STR "-2147483648"
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
	if (**str && !is_valid_str(*str))
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
			stack_add_first(&stacks->b, value);
		if (!is_valid)
			return (0);
		while (stacks->b)
			stack_push(&stacks->b, &stacks->a);
	}
	return (1);
}
