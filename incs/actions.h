/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 11:58:24 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 14:43:10 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

typedef struct s_action	t_action;

struct	s_action
{
	char		*value;
	t_action	*next;
};

void	action_print(t_action *head);

int		size_action(t_action *action);

int		action_add_first(t_action **head, const char *value);
int		action_del_all(t_action **head);
void	action_reverse(t_action **head);

#endif
