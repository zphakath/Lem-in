/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 22:55:23 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:42:27 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*str1;
	char	*to_find1;

	i = 0;
	str1 = (char *)str;
	to_find1 = (char *)to_find;
	if (to_find1[0] == '\0')
		return ((char *)str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while (str1[i + j] == to_find1[j] && to_find1[j] != '\0')
			j++;
		if (to_find1[j] == '\0')
			return ((char *)(str1 + i));
		i++;
	}
	return (NULL);
}
