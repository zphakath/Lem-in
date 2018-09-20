/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:58:17 by zphakath          #+#    #+#             */
/*   Updated: 2018/07/04 16:20:57 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	move_ants(t_lemin *ptr, t_path *path, int ant, int iter)
{
	int print;

	print = iter - ant;
	if (print > 0)
	{
		while (path)
		{
			if (print == 1)
			{
				ft_putchar('L');
				ft_putnbr(ant + 1);
				ft_putchar('-');
				ft_putstr(path->room);
				ft_putchar(' ');
				if (((ant + 1) == ptr->ants) &&
						!ft_strcmp(path->room, ptr->end))
					return (1);
			}
			path = path->next;
			print--;
		}
	}
	return (0);
}

void		move(t_lemin *ptr)
{
	int	done;
	int	iter;
	int	ant;

	done = 0;
	iter = 1;
	ft_putchar('\n');
	while (!done)
	{
		ant = 0;
		while (ant < ptr->ants)
			done = move_ants(ptr, ptr->path, ant++, iter);
		iter++;
		ft_putchar('\n');
	}
}
