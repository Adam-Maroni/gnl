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

int	get_next_line(int fd, char **line)
{
	size_t	read_bytes;
	char	*buffer;
	static char	*string = NULL;
	char	*tmp;
	char	*n;

	read_bytes = 1;
	buffer = (char*)ft_calloc(BUFFER_SIZE, sizeof(*buffer));
	while (!ft_strchr(buffer, (int)'\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (!(string = ft_strjoin(string, buffer)))
			return (-1);
	}
	free(buffer);
	if ((n = ft_strchr(string, (int)'\n')))
	{
		ft_strlcpy(*line, string, n - string + 1);
		tmp = string;
		string = ft_strdup(++n);
		free(tmp);
		return (1);
	}
	free(string);
	return (read_bytes);
}
