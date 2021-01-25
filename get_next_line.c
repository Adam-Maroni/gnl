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

void	free_mem(char **pt)
{
	if (*pt)
	{
		free(*pt);
		*pt = NULL;
	}
}

int		string2line(char **string, char **line, char *character)
{
	char	*tmp;
	int		rt;

	rt = 0;
	tmp = *string;
	*line = (char*)ft_calloc(character - *string + 2, sizeof(**line));
	ft_strlcpy(*line, *string, character - *string + 1);
	if (*character != '\0')
	{
		character++;
		rt = 1;
	}
	*string = ft_strdup(character);
	free_mem(&tmp);
	return (rt);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	char		*tmp;
	int			rd;
	static char	*string = NULL;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(*buf));
	rd = 1;
	if (BUFFER_SIZE <= 0 || !buf || !line || fd <= 0)
		return (-1);
	(!string) ? (string = (char*)ft_calloc(1, sizeof(*string))) : NULL;
	while ((!ft_strchr(string, (int)'\n')))
	{
		if ((rd = read(fd, buf, BUFFER_SIZE)) == 0)
			break ;
		else if (rd < 0)
			return (-1);
		tmp = string;
		if ((string = ft_strjoin(string, buf)))
			ft_bzero(buf, ft_strlen(buf));
		free_mem(&tmp);
	}
	free_mem(&buf);
	if (ft_strchr(string, (int)'\n'))
		return (string2line(&string, line, ft_strchr(string, (int)'\n')));
	return (string2line(&string, line, ft_strchr(string, (int)'\0')));
}
