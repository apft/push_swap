/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:44:57 by apion             #+#    #+#             */
/*   Updated: 2019/04/02 12:51:44 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define ERROR_STACK	0
# define SUCCESS_STACK	1
# define EMPTY_STACK	2

typedef struct s_stack	t_stack;
struct		s_stack
{
	int		value;
	t_stack	*next;
};

void		stack_print(t_stack *head);

int			stack_push(t_stack **head, int value);

int			stack_del_first(t_stack **head);
int			stack_del_all(t_stack **head);

int			stack_swap(t_stack *head);
int			stack_rotate(t_stack **head);
int			stack_reverse_rotate(t_stack **head);

#endif
