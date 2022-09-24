/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:34:31 by muerdoga          #+#    #+#             */
/*   Updated: 2022/07/27 11:34:33 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_scan(char c, va_list arg);
int	ft_printf(const char *sign, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_convert(size_t data, char *base);
int	ft_putnbr(int nbr);

#endif
