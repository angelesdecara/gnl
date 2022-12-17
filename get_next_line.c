/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:37:56 by angrodri          #+#    #+#             */
/*   Updated: 2022/12/17 16:22:44 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line[BUFFER_SIZE];
	static int	counter = 0;
	char		*str;
	char		newl;

	while (read(fd, line, BUFFER_SIZE) > 0) // && str != '\n')
	{
		// check line has '\n' 
		if (ft_strchr(line, '\n') != NULL)
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
