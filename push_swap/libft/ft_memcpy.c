/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:35:15 by matanton          #+#    #+#             */
/*   Updated: 2022/06/14 18:56:56 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!(dst == NULL && src == NULL) && n > 0)
	{
		while (n--)
			((char *) dst)[n] = ((char *) src)[n];
	}
	return (dst);
}
