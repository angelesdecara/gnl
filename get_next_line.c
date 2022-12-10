/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:37:56 by angrodri          #+#    #+#             */
/*   Updated: 2022/12/10 15:24:23 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char*	line;
	int				counter;
	char			str;

	counter = 0;
	while (read(fd, &str, 1) > 0 && str != '\n')
	{
		counter++;
		write(1, &str, 1);
	}
	line = malloc((counter + 1) * sizeof(char));
	read(fd, line, counter);
	line[counter + 1] = '\0';
	// pensar en static variable como string o file descriptor pensando en bonus
	return(line);
}

int main(void)
{
	int	fd;

	fd = open("foo.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
}
