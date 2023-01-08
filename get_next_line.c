/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:37:56 by angrodri          #+#    #+#             */
/*   Updated: 2023/01/08 21:04:47 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	char			*str;
	static char		*remainer;

	line = ft_calloc(BUFFER_SIZE + 2, sizeof(char));
	if (!line)
		return (NULL);
	if (read(fd, line, BUFFER_SIZE) > 0)
	{
		str = subsubstr(line, remainer);
		printf("str = %s\n",str);
		return (str);
	}
	else
		return (0);
}

char	*subsubstr(char *line, char *remainer)
{
	int		i;
	char	*ret;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	ret = ft_calloc((i + 1), sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	if (remainer)
		ret = ft_strjoin(ret, remainer);
	ft_saveremain(line, remainer);
	return (ret);
}

void	ft_saveremain(char *line, char *remain)
{
	int	i;
	int	len;
	int	lenline;

	i = 0;
	len = ft_strlen(line);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	lenline = i;
	remain = ft_calloc(lenline + 2, sizeof(char));
	i = 0;
	while (i + lenline <= len)
	{
		remain[i] = line[i + lenline];
		i++;
	}
	remain[i] = '\0';
}
