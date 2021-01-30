/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:37:08 by amaroni           #+#    #+#             */
/*   Updated: 2021/01/30 15:09:13 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_mem(char **pt)
{
	int	i;

	i = 0;
	while (i < 4096)
	{
		if (pt[i])
		{
			free(pt[i]);
			pt[i] = NULL;
		}
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	unsigned long rt;

	rt = 0;
	if (s)
		while (*(s + rt) != '\0')
			rt++;
	return (rt);
}

int		str2line(char **str, char **line, char *character)
{
	char	*tmp;
	int		rt;

	rt = 0;
	tmp = *str;
	*line = (char*)ft_calloc(character - *str + 1, sizeof(**line));
	ft_strlcpy(*line, *str, character - *str + 1);
	if (*character != '\0')
	{
		character++;
		rt = 1;
	}
	*str = ft_strdup(character);
	free(tmp);
	tmp = NULL;
	return (rt);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	int			rd;
	static char	*str[4096];

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(*buf));
	if (!(str[fd]))
		str[fd] = (char*)ft_calloc(1, sizeof(**str));
	while ((!ft_strchr(str[fd], '\n'))
	&& ((rd = read(fd, buf, BUFFER_SIZE)) != 0))
	{
		if (rd < 0)
		{
			free_mem(str);
			free(buf);
			return (-1);
		}
		buf[rd] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
	}
	free(buf);
	if (ft_strchr(str[fd], (int)'\n'))
		return (str2line(&(str[fd]), line, ft_strchr(str[fd], (int)'\n')));
	return (str2line(&(str[fd]), line, ft_strchr(str[fd], (int)'\0')));
}
