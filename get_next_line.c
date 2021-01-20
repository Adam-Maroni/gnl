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
	int i;

	i = 0;
	tmp = *string;
	while (*string[i] != *character)
	{
		*(line[i]) = *string[i];
		i++;
	}
	*string = ft_strdup(character);
	free(tmp);
}

int	get_next_line(int fd, char **line)
{
	static char* string;
	size_t rd;
	char *buf;

	buf = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(*buf));

	while ((rd = read(fd, buf, BUFFER_SIZE)) > 0 && !ft_strchr(buf, (int)'\n'))
		if (!(string = ft_strjoin(string, buf)))
			return (-1);
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
				string2line(&string, line, ft_strchr(string, (int)'\0'));
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


