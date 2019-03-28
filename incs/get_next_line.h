/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:10:22 by apion             #+#    #+#             */
/*   Updated: 2019/03/29 16:51:13 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define GNL_EOF	-1
# define GNL_ERROR	-2

# define BUFF_SIZE	8

typedef struct	s_gnl
{
	char		buff[BUFF_SIZE];
	ssize_t		buff_read;
	ssize_t		index_start;
	ssize_t		index_eol;
	char		*temp;
	ssize_t		temp_size;
}				t_gnl;

ssize_t			get_next_line(const int fd, char **line);

#endif
