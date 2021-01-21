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
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif


void string2line(char **string, char **line, char *character)
{
	char *tmp;
	char *tmp2;

	tmp = *string;
	tmp2 = *line;
	*line = (char*)ft_calloc(character - *string + 2, sizeof(**line));
	ft_strlcpy(*line, *string, character - *string + 1);
	*string = ft_strdup(++character);
	if (tmp)
		free(tmp);
	if (tmp2)
		free(tmp2);
}

int	get_next_line(int fd, char **line)
{
	static char* string = NULL;
	size_t rd;
	char *buf;

	buf = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(*buf));
	if (!string)
		string = (char*)ft_calloc(1, sizeof(*string));

	while ((!ft_strchr(string, (int)'\n')))
	{
		if ((rd = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			if (!(string = ft_strjoin(string, buf)))
				return (-1);
			else
				ft_bzero(buf, ft_strlen(buf));
		}
		else
			break;
	}
	free(buf);

	if (rd == 0)
	{
		if (!(*string))
		{
			free(string);
			return (0);
		}
		else
		{
			if (ft_strchr(string, (int)'\n'))
				string2line(&string, line, ft_strchr(string, (int)'\n'));
			else
			{
				string2line(&string, line, ft_strchr(string, (int)'\0'));
				ft_bzero(string, ft_strlen(string));
			}
			return (1);
		}
	}
	else if (ft_strchr(string, (int)'\n'))
	{
		string2line(&string, line, ft_strchr(string, (int)'\n'));
		return (1);
	}
	else
		return (-1);
}


