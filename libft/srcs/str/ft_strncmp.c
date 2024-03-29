/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:47:19 by apion             #+#    #+#             */
/*   Updated: 2018/11/23 14:20:50 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && *(s1 + i) && *(s2 + i) && *(s1 + i) == *(s2 + i))
		i++;
	return ((i == n) ? 0 :
			*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}
