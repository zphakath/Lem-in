/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:15:01 by zphakath          #+#    #+#             */
/*   Updated: 2018/07/05 16:35:57 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		bfs(t_lemin **ptr)
{
	(*ptr)->r = getroom(&(*ptr)->rooms, (*ptr)->start);
	push(&(*ptr)->q, (*ptr)->r);
	while ((*ptr)->q != NULL)
	{
		(*ptr)->r = pop(&(*ptr)->q);
		if (strcmp((*ptr)->r->room, (*ptr)->end) == 0)
		{
			create_path(&(*ptr)->path, (*ptr)->r);
			break ;
		}
		while ((*ptr)->r->connection)
		{
			(*ptr)->conn = getroom(&(*ptr)->rooms,
					(*ptr)->r->connection->room);
			if (!(*ptr)->conn->visited)
			{
				(*ptr)->conn->parent = (*ptr)->r;
				push(&(*ptr)->q, (*ptr)->conn);
			}
			(*ptr)->r->connection = (*ptr)->r->connection->next;
		}
		(*ptr)->r->visited = 1;
	}
}

static t_lemin	*init(void)
{
	t_lemin *ptr;

	ptr = (t_lemin *)malloc(sizeof(t_lemin));
	ptr->path = NULL;
	ptr->rooms = NULL;
	ptr->start = NULL;
	ptr->q = NULL;
	ptr->end = NULL;
	ptr->ants = 0;
	ptr->error = 0;
	return (ptr);
}

static void		read_stdin(t_lemin **ptr)
{
	int		carry_flag;
	char	*line;
	char	**sp_r;
	char	**sp_c;

	carry_flag = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		line = comments(line);
		sp_r = ft_strsplit(line, ' ');
		sp_c = ft_strsplit(line, '-');
		if (!ft_strncmp(line, "##start", 7))
			carry_flag = 1;
		else if (!ft_strncmp(line, "##end", 5))
			carry_flag = 2;
		else if (sp_r[0] && sp_r[1] && sp_r[2] && !sp_r[3])
			update_rooms(ptr, sp_r, &carry_flag);
		else if (sp_c[0] && sp_c[1] && !sp_c[2])
			update_connections(ptr, sp_c);
		else
			update_ants(ptr, line);
		(line) ? free(line) : 0;
	}
}

int				main(void)
{
	t_lemin	*lemin;

	lemin = init();
	read_stdin(&lemin);
	(lemin->rooms && lemin->start &&
		lemin->end && lemin->ants && !lemin->error) ? bfs(&lemin) : 0;
	(lemin->path) ? move(lemin) : ft_putstr("\nERROR\n");
	free_ptr(&lemin);
	return (0);
}
