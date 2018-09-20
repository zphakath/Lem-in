/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:00:01 by zphakath          #+#    #+#             */
/*   Updated: 2018/07/04 16:22:08 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	push(t_queue **head, t_rooms *room)
{
	t_queue *current;

	if (!*head)
	{
		(*head) = (t_queue *)malloc(sizeof(t_queue));
		(*head)->room = room;
		(*head)->next = NULL;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_queue *)malloc(sizeof(t_queue));
	current->next->room = room;
	current->next->next = NULL;
}

void	add_path(t_path **head, char *room)
{
	t_path *current;

	if (!*head)
	{
		(*head) = (t_path *)malloc(sizeof(t_path));
		(*head)->room = strdup(room);
		(*head)->next = NULL;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_path *)malloc(sizeof(t_path));
	current->next->room = strdup(room);
	current->next->next = NULL;
}

void	create_path(t_path **head, t_rooms *root)
{
	if (root->parent == NULL)
		return ;
	create_path(head, root->parent);
	add_path(head, root->room);
}

t_rooms	*pop(t_queue **head)
{
	t_rooms *room;
	t_queue *temp;

	temp = *head;
	room = (*head)->room;
	*head = (*head)->next;
	free(temp);
	return (room);
}
