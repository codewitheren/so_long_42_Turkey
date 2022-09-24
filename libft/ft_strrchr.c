/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:51:35 by muerdoga          #+#    #+#             */
/*   Updated: 2022/06/23 16:46:17 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	while (*(s + i) != (char)c && i > 0)
	{
		i--;
	}
	if (i == 0 && *(s + i) != (char)c)
		return (0);
	return ((char *)(s + i));
}
