/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:37:56 by angrodri          #+#    #+#             */
/*   Updated: 2023/07/18 19:26:14 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*str;
	static char		*remainer;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0))
	{
		if (remainer)
		{
			remainer = NULL;
			free(remainer);
		}
		return (NULL);
	}
	remainer = ft_readbuffer(fd, remainer);
	if (!remainer)
		return (NULL);
	str = ft_getline(remainer);
	remainer = ft_nextremainer(remainer);
	return (str);
}

char	*ft_readbuffer(int fd, char *remainer)
{
	int		i;
	char	*buffer;

	if (!remainer)
		remainer = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		remainer = ft_cpyfree(remainer, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (remainer);
}

char	*ft_cpyfree(char *remainer, char *buffer)
{
	char	*aux;

	aux = ft_strjoin(remainer, buffer);
	free(remainer);
	return (aux);
}

char	*ft_getline(char *remainer)
{
	int		i;
	char	*str;

	i = 0;
	if (!remainer[i])
		return (NULL);
	while (remainer[i] && remainer[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (remainer[i] && remainer[i] != '\n')
	{
		str[i] = remainer[i];
		i++;
	}
	if (remainer[i] && remainer[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_nextremainer(char *allread)
{
	int		i;
	int		j;
	char	*remainer;

	i = 0;
	while (allread[i] && allread[i] != '\n')
		i++;
	if (!allread[i])
	{
		free(allread);
		return (NULL);
	}
	remainer = ft_calloc(ft_strlen(allread) - i + 1, sizeof(char));
	if (!remainer)
		return (NULL);
	j = 0;
	i++;
	while (allread[i])
		remainer[j++] = allread[i++];
	remainer[j] = '\0';
	free(allread);
	return (remainer);
}
