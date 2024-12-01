/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:46:12 by kadachi           #+#    #+#             */
/*   Updated: 2024/11/30 18:26:19 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*cur;

	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	cur = ptr;
	while (s1 != NULL && *s1 != '\0')
		*cur++ = *s1++;
	while (s2 != NULL && *s2 != '\0')
		*cur++ = *s2++;
	*cur = '\0';
	return (ptr);
}

int	ft_fgetc(int fd)
{
	static char		buf[BUFFER_SIZE];
	static ssize_t	pos;
	static ssize_t	size;

	if (pos >= size)
	{
		size = read(fd, buf, BUFFER_SIZE);
		pos = 0;
		if (size <= 0)
			return (EOF);
	}
	return ((unsigned char)buf[pos++]);
}
