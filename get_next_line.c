/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:37:08 by amaroni           #+#    #+#             */
/*   Updated: 2021/01/16 22:07:58 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned long rt;

	rt = 0;
	if (s)
		while (*(s + rt) != '\0')
			rt++;
	return (rt);
}

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((char*)s + i) = '\0';
		i++;
	}
}

void	free_mem(char **pt)
{
	if (*pt)
	{
		free(*pt);
		*pt = NULL;
	}
}

int		str2line(char **str, char **line, char *character)
{
	char	*tmp;
	int		rt;

	rt = 0;
	tmp = *str;
	*line = (char*)ft_calloc(character - *str + 2, sizeof(**line));
	ft_strlcpy(*line, *str, character - *str + 1);
	if (*character != '\0')
	{
		character++;
		rt = 1;
	}
	*str = ft_strdup(character);
	free_mem(&tmp);
	return (rt);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	char		*tmp;
	int			rd;
	static char	*str = NULL;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(*buf));
	(!str) ? (str = (char*)ft_calloc(1, sizeof(*str))) : NULL;
	while ((!ft_strchr(str, '\n')) && ((rd = read(fd, buf, BUFFER_SIZE)) != 0))
	{
		if (rd < 0)
		{
			free_mem(&buf);
			return (-1);
		}
		tmp = str;
		if ((str = ft_strjoin(str, buf)))
			ft_bzero(buf, BUFFER_SIZE + 1);
		free_mem(&tmp);
	}
	free_mem(&buf);
	if (ft_strchr(str, (int)'\n'))
		return (str2line(&str, line, ft_strchr(str, (int)'\n')));
	return (str2line(&str, line, ft_strchr(str, (int)'\0')));
}
