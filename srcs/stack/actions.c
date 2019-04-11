/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:15:58 by apion             #+#    #+#             */
/*   Updated: 2019/04/11 13:13:59 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "libft.h"
#include "ft_printf.h"

static t_action	*create_action(const char *value)
{
	t_action	*node;

	node = (t_action *)malloc(sizeof(*node));
	if (!node)
		return (0);
	node->value = ft_strdup(value);
	if (!node->value)
	{
		free(node);
		return (0);
	}
	node->next = 0;
	return (node);
}

int				action_add_first(t_action **head, const char *value)
{
	t_action	*node;

	if (!head)
		return (0);
	node = create_action(value);
	if (!node)
		return (0);
	node->next = *head;
	*head = node;
	return (1);
}

void			action_reverse(t_action **head)
{
	t_action	*tmp;
	t_action	*prev;

	if (!head || !*head)
		return ;
	prev = 0;
	while ((*head)->next)
	{
		tmp = (*head)->next;
		(*head)->next = prev;
		prev = (*head);
		*head = tmp;
	}
	(*head)->next = prev;
}

void			action_print(t_action *head)
{
	t_action	*node;

	action_reverse(&head);
	node = head;
	while (node)
	{
		ft_printf("%s\n", node->value);
		node = node->next;
	}
	action_reverse(&head);
}

int				action_del_all(t_action **head)
{
	t_action	*tmp;

	if (!head)
		return (0);
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->value);
		free(tmp);
	}
	return (1);
}
