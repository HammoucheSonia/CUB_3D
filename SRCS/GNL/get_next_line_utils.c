/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:58:38 by mabid             #+#    #+#             */
/*   Updated: 2023/01/07 14:58:39 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return (NULL);
	return (NULL);
}

char	*ft_strjoin(char *s1, char	*s2)
{
	char	*join;
	char	*ptr;
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	join = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 1) * \
	sizeof(char)));
	if (!join)
		return (NULL);
	ptr = join;
	if (s1)
	{
		temp = s1;
		while (*s1)
		{
			*join++ = *s1++;
		}
		free(temp);
	}
	if (*s2)
		while (*s2)
			*join++ = *s2++;
	*join = '\0';
	return (ptr);
}
