/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:27:51 by apion             #+#    #+#             */
/*   Updated: 2019/01/08 13:38:15 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putstr_fd(char const *s, int fd)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i++))
		;
	return (write(fd, s, i));
}
