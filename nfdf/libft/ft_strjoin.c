/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_old.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:40:00 by matanton          #+#    #+#             */
/*   Updated: 2023/02/10 19:47:30 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*st;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	st = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (st == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		st[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		st[i + j] = s2[j];
		j++;
	}
	st[i + j] = '\0';
	free(s1);
	return (st);
}
