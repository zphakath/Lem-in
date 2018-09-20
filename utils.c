/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:01:42 by zphakath          #+#    #+#             */
/*   Updated: 2018/07/04 16:14:42 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_double_ptr(char **ptr)
{
	int i;

	i = -1;
	while (ptr[++i])
		(ptr[i]) ? free(ptr[i]) : 0;
	(ptr) ? free(ptr) : 0;
}

void	update_ants(t_lemin **ptr, char *line)
{
	if ((*ptr)->ants <= 0)
		(*ptr)->ants = ft_atoi(line);
}

void	update_connections(t_lemin **ptr, char **sp_c)
{
	if (!getroom(&(*ptr)->rooms, sp_c[0]) ||
			!getroom(&(*ptr)->rooms, sp_c[1]))
		(*ptr)->error = 1;
	(!(*ptr)->error) ? connect_rooms(&(*ptr)->rooms, sp_c[0], sp_c[1]) : 0;
	free_double_ptr(sp_c);
}

char	*comments(char *s)
{
	int		i;
	char	*ret;
	char	*old_mem;

	old_mem = s;
	i = 0;
	if (s[i] != '#' && s[i + 1] != '#')
	{
		while (s[i] && s[i] != '#')
			i++;
		ret = ft_strnew(i);
		i = 0;
		while (s[i] && s[i] != '#')
		{
			ret[i] = s[i];
			i++;
		}
		ret[i] = '\0';
		free(old_mem);
		return (ret);
	}
	return (s);
}
