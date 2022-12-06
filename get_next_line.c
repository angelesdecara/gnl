/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:37:56 by angrodri          #+#    #+#             */
/*   Updated: 2022/12/06 19:20:47 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char*	line;
	int		counter;
	char	str;

	counter = 0;
	while (read(fd, str, 1) > 0 && str != '\n && str != '\n'')
	{
		counter++;
	}
	// pensar en static variable como string o file descriptor pensando en bonus
}
