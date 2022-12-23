/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:49:54 by matanton          #+#    #+#             */
/*   Updated: 2022/06/14 22:19:10 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	p = ((char *) ft_calloc(sizeof (char), (ft_strlen(s1) + 1)));
	i = 0;
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, ft_strlen(s1));
	return (p);
}
