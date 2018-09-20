/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:58:33 by zphakath          #+#    #+#             */
/*   Updated: 2018/07/04 15:58:56 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	free_queue(t_queue *q)
{
	while (q)
		pop(&q);
}

static void	free_path(t_path *ptr)
{
	t_path *tmp;

	while (ptr)
	{
		tmp = ptr->next;
		free(ptr->room);
		free(ptr);
		ptr = tmp;
	}
}

static void	free_rooms(t_rooms *ptr)
{
	t_rooms *tmp;

	while (ptr)
	{
		tmp = ptr->next;
		free_rooms(ptr->connection);
		free(ptr->room);
		free(ptr);
		ptr = tmp;
	}
}

void		free_ptr(t_lemin **ptr)
{
	(*ptr)->start ? free((*ptr)->start) : 0;
	(*ptr)->end ? free((*ptr)->end) : 0;
	(*ptr)->path ? free_path((*ptr)->path) : 0;
	(*ptr)->q ? free_queue((*ptr)->q) : 0;
	(*ptr)->rooms ? free_rooms((*ptr)->rooms) : 0;
	(*ptr) ? free(*ptr) : 0;
}
