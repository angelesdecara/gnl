/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:37:56 by angrodri          #+#    #+#             */
/*   Updated: 2023/02/14 20:22:41 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				i;
	int				j;
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
		//check malloc...
		ft_strlcpy(str, remainer, i + 1);
		str[i] = '\n';
		ft_strlcpy(remainer, remainer + i + 1, ft_strlen(remainer) - i);
		free(line);
		return (str);
	}
	else
	{
		while (read(fd, line, BUFFER_SIZE) > 0 && !ft_strchr(line, '\n'))
		{
			if (remainer)
			{
				remainer = ft_strjoin(remainer, line);
			}
			//should I free line in this if above?
			else
			{
				remainer = ft_calloc(ft_strlen(line) + 2, sizeof(char));
				ft_strlcpy(remainer, line, ft_strlen(line) + 1);
			}
		}
		printf("line=%s, remainer=%s\n",line, remainer);
		if (ft_strlen(line) == 0 && !remainer)
		{
			printf("entered setting line to null\n");
			free(line);
			return (NULL);
		}
		if (!ft_strchr(line, '\n'))
			ft_bzero(line, BUFFER_SIZE + 2);
		printf("out of if: line=%s, remainer=%s\n",line, remainer);
	}
	if (remainer)
	{
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		str = ft_calloc(ft_strlen(remainer) + i + 2, sizeof(char));
		ft_strlcpy(str, remainer, ft_strlen(remainer) + 2);
		j = 0;
		while (line[j] != '\0' && line[j] != '\n')
		{
			str[j + ft_strlen(remainer)] = line[j];
			j++;
		}
		if (ft_strchr(line, '\n') || ft_strchr(remainer, '\n'))
			str[ft_strlen(str)] = '\n';
		free(remainer);
		remainer = ft_calloc(ft_strlen(line) - i + 2, sizeof(char));
		j = -1;
		while (line[i + 1 + j++] != '\0')
			remainer[j] = line[i + 1 + j];
		free(line);
		return (str);
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
