/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:41:37 by matanton          #+#    #+#             */
/*   Updated: 2022/10/10 11:13:04 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(unsigned long i)
{
	char	*base;
	int		j;

	base = "0123456789abcdef";
	j = 0;
	if (i == 0)
		j += ft_putchar('0');
	else
	{
		if (i >= 16)
		{
			ft_putptr(i / 16);
			ft_putptr(i % 16);
		}
		else
			ft_putchar(base[i]);
		j += count_hexa(i);
	}
	return (j);
}

int	count_hexa(unsigned long i)
{
	int	j;

	j = 0;
	while (i != 0)
	{
		j++;
		i = i / 16;
	}
	return (j);
}

int	ft_hexa(unsigned int i)
{
	char	*base;

	base = "0123456789abcdef";
	if (i == 0)
		return (ft_putchar('0'));
	if (i >= 16)
	{
		ft_hexa(i / 16);
		ft_hexa(i % 16);
	}
	else
		ft_putchar(base[i]);
	return (count_hexa(i));
}

int	ft_hexa_up(unsigned int i)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (i == 0)
		return (ft_putchar('0'));
	if (i >= 16)
	{
		ft_hexa_up(i / 16);
		ft_hexa_up(i % 16);
	}
	else
		ft_putchar(base[i]);
	return (count_hexa(i));
}
