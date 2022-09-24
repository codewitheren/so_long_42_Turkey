/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:10:53 by muerdoga          #+#    #+#             */
/*   Updated: 2022/06/28 13:31:58 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	src_len;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
	{
		substr = malloc(sizeof(char));
		if (!substr)
			return (NULL);
		*substr = '\0';
	}
	else
	{
		if ((src_len - start) < len)
			len = src_len - start;
		substr = malloc(sizeof(char) * (len + 1));
		if (!substr)
			return (NULL);
		ft_strlcpy(substr, (char *)(s + start), len + 1);
	}
	return (substr);
}
