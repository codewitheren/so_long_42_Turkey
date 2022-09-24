/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:40:38 by muerdoga          #+#    #+#             */
/*   Updated: 2022/08/02 19:25:29 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	f_strlen(char *save)
{
	size_t	i;

	i = 0;
	if (!save)
		return (0);
	while (save[i] != '\0')
		i++;
	return (i);
}

char	*f_strchr(char *save, int c)
{
	int	i;

	i = 0;
	if (!save)
		return (NULL);
	if (c == '\0')
		return (&save[f_strlen(save)]);
	while (save[i] != '\0')
	{
		if (save[i] == c)
			return (&save[i]);
		i++;
	}
	return (0);
}

char	*f_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*arry;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s1_len = f_strlen((char *)s1);
	s2_len = f_strlen((char *)s2);
	arry = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!arry)
		return (NULL);
	ft_strlcpy((arry), (char *)s1, s1_len + s2_len + 1);
	ft_strlcpy((arry + s1_len), (char *)s2, s1_len + s2_len + 1);
	free(s1);
	return (arry);
}
