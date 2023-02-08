/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:29:34 by matanton          #+#    #+#             */
/*   Updated: 2022/10/10 11:12:51 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	utoa_len(unsigned int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_utoa(unsigned int n)
{
	unsigned int	temp;
	int				size;
	char			*str;
	long int		i;

	temp = n;
	size = utoa_len(temp);
	str = malloc(sizeof(char [size + 1]));
	if (!str)
		return (0);
	str[size--] = '\0';
	if (n == 0)
		str[size] = 48;
	while (temp > 0)
	{
		str[size] = (temp % 10) + 48;
		temp = temp / 10;
		size--;
	}
	i = ft_putstr(str);
	free(str);
	return (i);
}
