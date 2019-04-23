/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_output.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:49:49 by apion             #+#    #+#             */
/*   Updated: 2019/04/05 11:55:10 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_OUTPUT_H
# define LIBFT_OUTPUT_H

# include <unistd.h>

ssize_t		ft_putchar(char c);
ssize_t		ft_putchar_fd(char c, int fd);
ssize_t		ft_putendl(char const *s);
ssize_t		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr(int n);
void		ft_putnbr_base(unsigned long n, const char *base);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr_hex(unsigned long n);
ssize_t		ft_putstr(char const *s);
ssize_t		ft_putstr_fd(char const *s, int fd);

#endif
