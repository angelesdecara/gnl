/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:36 by angrodri          #+#    #+#             */
/*   Updated: 2023/01/10 20:12:40 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*subsubstr(char *line, char *counter);
void	ft_saveremain(char *line, char *remain);
char	*ft_strchr(const char *s, int c);

#endif
