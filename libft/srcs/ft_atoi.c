/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:30:39 by apion             #+#    #+#             */
/*   Updated: 2019/04/02 14:42:39 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INT_MAX_LEN 10
#define INT_MAX_STR "2147483647"
#define INT_MIN_LEN 11
#define INT_MIN_STR "-2147483648"
#define INT_LEN_MAX INT_MIN_LEN

static int	is_digit_str(const char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

int		ft_is_valid_atoi_input(const char *str)
{
	int		len;

	len = ft_strlen(str);
	if (ft_isdigit(*str) && is_digit_str(str))
	{
		if (len > INT_MAX_LEN)
			return (0);
		else if (len == INT_MAX_LEN)
			return (ft_strcmp(str, INT_MAX_STR) <= 0);
		return (1);
	}
	else if (*str == '-' && is_digit_str(str + 1))
	{
		if (len > INT_MIN_LEN)
			return (0);
		else if (len == INT_MIN_LEN)
			return (ft_strcmp(str, INT_MIN_STR) <= 0);
		return (1);
	}
	return (0);
}

int		ft_atoi(const char *str)
{
	int		n;
	int		s;

	n = 0;
	s = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		s = *str++ == '-' ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		n = 10 * n + (*str++ - '0');
	return (s * n);
}
