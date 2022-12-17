/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:36 by angrodri          #+#    #+#             */
/*   Updated: 2022/12/17 16:26:19 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 1024
#endif

char			*get_next_line(int fd);
static size_t	ft_strlen(char *s);
static char		*ft_strjoin(char const *s1, char const *s2);
static void		ft_bzero(void *s, size_t n);
static void		*ft_calloc(size_t count, size_t size);
char			*subsubstr(char *line, int *counter);
char			*readbuf(int fd, char *str);

#endif
