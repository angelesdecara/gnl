/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:37:56 by angrodri          #+#    #+#             */
/*   Updated: 2023/02/25 17:50:51 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				i;
	char			*line;
	char			*str;
	static char		*remainer;

	line = ft_calloc(BUFFER_SIZE + 2, sizeof(char));
	if (!line)
		return (NULL);
	if (remainer && ft_strchr(remainer, '\n'))
	{
		i = 0;
		while (remainer[i] != '\n')
			i++;
		str = ft_calloc(i + 2, sizeof(char));
		ft_strlcpy(str, remainer, i + 1);
		str[i] = '\n';
		ft_strlcpy(remainer, remainer + i + 1, ft_strlen(remainer) - i);
		free(line);
		return (str);
	}
	else
	{
		while ((i = read(fd, line, BUFFER_SIZE)) > 0 && !ft_strchr(line, '\n'))
		{
			if (remainer)
			{
				remainer = ft_strjoin(remainer, line);
			}
			else
			{
				remainer = ft_calloc(ft_strlen(line) + 2, sizeof(char));
				ft_strlcpy(remainer, line, ft_strlen(line) + 1);
			}
		}
		if (i <= 0)
		{
			free(line);
			if (remainer && ft_strlen(remainer) > 0)
				return (remainer);
			else
				return (NULL);
		}
	}
	if (remainer)
	{
		i = 0;
		while (remainer[i] != '\0' && remainer[i] != '\n')
			i++;
		str = ft_calloc(i + 2, sizeof(char));
		ft_strlcpy(str, remainer, i + 1);
		if (ft_strchr(remainer, '\n') || ft_strchr(line, '\n'))
			str[i] = '\n';
		ft_strlcpy(line, remainer + i, ft_strlen(remainer) - i);
		remainer = line + 1;
	}
	else
		{
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		str = ft_calloc(i + 2, sizeof(char));
		ft_strlcpy(str, line, i + 1);
		if (line[i] == '\n')
			str[i] = '\n';
		if (ft_strlen(str) != ft_strlen(line))
		{
			remainer = ft_calloc(ft_strlen(line) - i + 2, sizeof(char));
			ft_strlcpy(remainer, line + i + 1, ft_strlen(line) - i); // -1
		}
	}
	free(line);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	while ((unsigned long)i < dstsize && *(src + i) != '\0' && dstsize > 0)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if ((unsigned long)i == dstsize)
		i--;
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
