/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:10:30 by matanton          #+#    #+#             */
/*   Updated: 2022/06/16 17:26:47 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;
	size_t	max;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	max = dstsize - dstlen - 1;
	if (dstlen > dstsize)
		return (dstsize + srclen);
	if (dstsize > 1 && (dstlen < (dstsize - 1)))
	{
		while (i < max && src[i])
		{
			dst[dstlen + i] = src[i];
				i++;
		}
		dst[dstlen + i] = '\0';
	}
	return (dstlen + srclen);
}
