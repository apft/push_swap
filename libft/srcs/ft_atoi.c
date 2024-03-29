/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:30:39 by apion             #+#    #+#             */
/*   Updated: 2018/11/09 19:42:16 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		n;
	int		s;

	n = 0;
	s = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		s = *str++ == '-' ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		n = 10 * n + (*str++ - '0');
	return (s * n);
}
