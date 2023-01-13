/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:30:44 by angrodri          #+#    #+#             */
/*   Updated: 2023/01/13 20:36:46 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		n1;
	int		n2;

	n1 = ft_strlen((char *)s1);
	n2 = ft_strlen((char *)s2);
	ret = malloc((n1 + n2 + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = -1;
	while (++i < n1)
		*(ret + i) = *(s1 + i);
	i--;
	while (++i < n1 + n2)
		*(ret + i) = *(s2 + i - n1);
	*(ret + i) = '\0';
	return (ret);
}

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

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	while ((unsigned long)i < dstsize && *(src + i) != '\0')
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

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("foo.txt", O_RDONLY);
//	str=ft_calloc(5,sizeof(char));
//	while (read(fd, str, 4) > 0 && !ft_strchr(str, '\n'))
//	{
//		printf("4 chars read = %s\n", str);
	//	printf("str[1]=%s\n", str+1);
//	}
	printf("first call\n");
	str = get_next_line(fd);
	write(1, str, ft_strlen(str));
	printf("second call\n");
	str = get_next_line(fd);
	write(1, str, ft_strlen(str));
	close(fd);
}
