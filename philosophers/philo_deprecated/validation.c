/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:54:06 by matanton          #+#    #+#             */
/*   Updated: 2023/03/06 10:45:25 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_num(char *string)
{
	int	j;
	int	s;

	j = 1;
	s = ft_strlen(string);
	if (((string[0] == '+' || string[0] == '-') && string[1]) \
			|| ft_isdigit(string[0]))
	{
		while (j <= s)
		{
			if (ft_isdigit(string[j]))
				j++;
			else
				return (0);
		}
	}
	else
		return (0);
	return (1);
}

long signed int	ft_latoi(char *str)
{
	int			i;
	int			sign;
	long int	r;

	i = 0;
	sign = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (str[i] - '0') + (r * 10);
		i++;
	}
	return (r * sign);
}
