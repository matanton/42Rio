/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:19:01 by matanton          #+#    #+#             */
/*   Updated: 2022/06/11 19:28:41 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!src && !dst)
		return (NULL);
	if (dst > src)
	{
		i = len;
		while (i-- > 0)
		{
			((char *) dst)[i] = ((char *) src)[i];
		}
	}
	else
		i = 0;
	while (i < len)
	{
		((char *) dst)[i] = ((char *) src)[i];
			i++;
	}
	return (dst);
}
