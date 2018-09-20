/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:00:17 by zphakath          #+#    #+#             */
/*   Updated: 2018/07/05 15:49:04 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_room(t_rooms **head, char *room)
{
	t_rooms *current;

	if (!*head)
	{
		(*head) = (t_rooms *)malloc(sizeof(t_rooms));
		(*head)->room = strdup(room);
		(*head)->connection = NULL;
		(*head)->parent = NULL;
		(*head)->visited = 0;
		(*head)->next = NULL;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_rooms *)malloc(sizeof(t_rooms));
	current->next->room = strdup(room);
	current->next->connection = NULL;
	current->next->parent = NULL;
	current->next->visited = 0;
	current->next->next = NULL;
}

t_rooms	*getroom(t_rooms **head, char *room)
{
	t_rooms *current;

	current = *head;
	while (current != NULL)
	{
		if (strcmp(room, current->room) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	connect_rooms(t_rooms **rooms, char *r1, char *r2)
{
	t_rooms *room1;
	t_rooms *room2;

	room1 = getroom(rooms, r1);
	room2 = getroom(rooms, r2);
	add_room(&room1->connection, r2);
	add_room(&room2->connection, r1);
}

void	update_rooms(t_lemin **ptr, char **sp_r, int *carry_flag)
{
	if ((*carry_flag == 1 && (*ptr)->start) ||
			(*carry_flag == 2 && (*ptr)->end))
		(*ptr)->error = 1;
	if (*carry_flag == 1)
		(*ptr)->start = ft_strdup(sp_r[0]);
	if (*carry_flag == 2)
		(*ptr)->end = ft_strdup(sp_r[0]);
	if (sp_r[0][0] == 'L')
		(*ptr)->error = 1;
	(!(*ptr)->error) ? add_room(&(*ptr)->rooms, sp_r[0]) : 0;
	*carry_flag = 0;
	free_double_ptr(sp_r);
}
