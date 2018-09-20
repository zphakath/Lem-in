/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:08:19 by zphakath          #+#    #+#             */
/*   Updated: 2018/07/05 15:57:11 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H

# define _LEMIN_H
# define BUFF_SIZE 300000
# include "libft/libft.h"

typedef struct			s_rooms
{
	char				*room;
	struct s_rooms		*connection;
	struct s_rooms		*parent;
	struct s_rooms		*next;
	int					visited;
}						t_rooms;

typedef struct			s_queue
{
	t_rooms				*room;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_path
{
	char				*room;
	struct s_path		*next;
}						t_path;

typedef	struct			s_lemin
{
	t_path				*path;
	t_rooms				*rooms;
	int					ants;
	char				*start;
	char				*end;
	int					error;
	t_queue				*q;
	t_rooms				*r;
	t_rooms				*conn;
}						t_lemin;

int						get_next_line(const int fd, char **line);
void					add_room(t_rooms **head, char *room);
t_rooms					*getroom(t_rooms **head, char *room);
void					connect_rooms(t_rooms **rooms, char *r1, char *r2);
void					update_rooms(t_lemin **ptr,
							char **sp_r, int *carry_flag);
void					push(t_queue **head, t_rooms *room);
void					add_path(t_path **head, char *room);
void					create_path(t_path **head, t_rooms *root);
t_rooms					*pop(t_queue **head);
void					free_double_ptr(char **ptr);
void					update_ants(t_lemin **ptr, char *line);
void					update_connections(t_lemin **ptr, char **sp_c);
char					*comments(char *s);
void					move(t_lemin *ptr);
void					free_ptr(t_lemin **ptr);

#endif
