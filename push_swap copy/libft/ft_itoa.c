/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:32:55 by matanton          #+#    #+#             */
/*   Updated: 2022/06/16 17:12:05 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_len(int n)
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

static void	ifneg(int *size, int *n, int *temp)
{
	*size = 0;
	if (*n < 0)
	{
		(*size)++;
		*temp = *n * (-1);
	}
	else
		*temp = *n;
}

char	*ft_itoa(int n)
{
	int		temp;
	int		size;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup ("-2147483648"));
	ifneg(&size, &n, &temp);
	size = size + itoa_len(temp);
	str = ft_calloc(1, sizeof(char [size + 1]));
	if (!str)
		return (NULL);
	size--;
	if (n == 0)
		str[size] = 48;
	while (temp > 0)
	{
		str[size] = (temp % 10) + 48;
		temp = temp / 10;
		size--;
	}
	if (n < 0)
		str[size] = '-';
	return (str);
}
