/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:16:22 by apion             #+#    #+#             */
/*   Updated: 2019/04/12 12:41:40 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# include "libft_bitwise.h"
# include "libft_char.h"
# include "libft_list.h"
# include "libft_output.h"
# include "libft_mem.h"
# include "libft_str.h"
# include "libft_math.h"

int				ft_istype_str(const char *str, int (*istype)(int));

void			ft_swap(void *a, void *b, int flag);
int				ft_atoi(const char *s);
char			*ft_itoa(int n);

void			ft_print_mem(void *addr, size_t n);

#endif
