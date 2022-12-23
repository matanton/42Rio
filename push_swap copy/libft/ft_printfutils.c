/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:29:34 by matanton          #+#    #+#             */
/*   Updated: 2022/10/10 11:12:39 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

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

int	ft_itoa_pf(int n)
{
	int			temp;
	int			size;
	char		*str;
	long int	i;

	if (n == -2147483648)
		return (ft_putstr ("-2147483648"));
	ifneg(&size, &n, &temp);
	size = size + itoa_len(temp);
	str = malloc(sizeof(char [size + 1]));
	str[size--] = '\0';
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
	i = ft_putstr(str);
	free(str);
	return (i);
}
