/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:37:56 by angrodri          #+#    #+#             */
/*   Updated: 2023/01/08 18:58:02 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line[BUFFER_SIZE];
	char			*str;
	static	char	*remainer;

	line = ft_calloc(BUFFER_SIZE + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (read(fd, line, BUFFER_SIZE) > 0) // && str != '\n')
	{
		// check line has '\n' 
		if (ft_strchr(&line, '\n') != NULL)
			{
				// we shall return ft_strchr(line, '\n')
				// and set a comeback point to that location
				str = subsubstr(line, &counter);
				return (str);
			}
	//	if ()
	}
	// pensar en static variable como string o file descriptor pensando en bonus
	return(line);
}
