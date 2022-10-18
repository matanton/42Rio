/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:15:52 by matanton          #+#    #+#             */
/*   Updated: 2022/10/10 11:13:38 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_format(va_list arg, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (format == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (format == 'd' || format == 'i')
		len += ft_itoa_pf(va_arg(arg, int));
	else if (format == 'u')
		len += ft_utoa(va_arg(arg, unsigned int));
	else if (format == '%')
		len += ft_putchar('%');
	else if (format == 'x')
		len += ft_hexa(va_arg(arg, unsigned int));
	else if (format == 'X')
		len += ft_hexa_up(va_arg(arg, unsigned int));
	else if (format == 'p')
		return (write(1, "0x", 2) + ft_putptr(va_arg(arg, unsigned long)));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format(arg, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
