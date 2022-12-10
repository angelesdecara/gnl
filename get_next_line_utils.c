/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:30:44 by angrodri          #+#    #+#             */
/*   Updated: 2022/12/10 21:18:31 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*c;

	c = s;
	i = 0;
	while ((unsigned long)i < n)
	{
		*(c + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (0);
	ptr = malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}



char	*subsubstr(char *line, int *counter)
{
	int		i;
	char	*ret;

	i = 0;
	while (line[*counter + i] != '\n' || line[*counter + i] != '\0') 
		i++;
	ret = ft_calloc((i + 1), sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (line[*counter + i] != '\n' || line[*counter + i] != '\0')
	{
		ret[i] = line[*counter + i];
		i++;
	}
	ret[i] = '\0';
	*counter = *counter + i;
	return(ret);
}

char	*readbuf(int fd, char *str)
{
	char	*buf[BUFFER_SIZE];
	int		i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &str, 0) < 0)
		return (NULL);
	if (str == NULL)
		str = calloc(2,  sizeof(char));
	while (!(ft_strchr(str, '\n')))
	{
		if (i == read(fd, buf, BUFFER_SIZE) < 0)
			return (NULL);
		*(buf + i) = '\0';
		str = ft_strjoin(str, buf);
		if (str[0] == '\0' || i == 0)
			break;
	}
	return (str);
}

int	main(void)
{
	int			fd;
	static char	*str;

	fd = open("foo.txt", O_RDONLY);
	str = readbuf(fd, str);
	write(1, str, 100);
	//get_next_line(fd);
	close(fd);
}
