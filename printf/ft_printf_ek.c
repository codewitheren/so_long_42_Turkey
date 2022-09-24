/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:33:28 by muerdoga          #+#    #+#             */
/*   Updated: 2022/07/27 11:33:29 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_convert(size_t data, char *base)
{
	int			len;
	static char	str[50];
	char		*ptr;

	len = ft_strlen(base);
	ptr = &str[49];
	*ptr = '\0';
	*--ptr = base[data % len];
	data = data / len;
	while (data)
	{
		*--ptr = base[data % len];
		data = data / len;
	}
	return (ft_putstr(ptr));
}

int	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr == -2147483648)
			return (ft_convert(2147483648, "0123456789") + 1);
		nbr = -1 * nbr;
		return (ft_convert(nbr, "0123456789") + 1);
	}
	return (ft_convert(nbr, "0123456789"));
}
