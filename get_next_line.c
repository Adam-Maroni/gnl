/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:37:08 by amaroni           #+#    #+#             */
/*   Updated: 2021/01/16 12:17:08 by amaroni          ###   ########.fr       */
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
	static char	*string;
	char	*n;

	if (!string)
		string = (char*)ft_calloc(BUFFER_SIZE, sizeof(*string));
	buffer = (char*)ft_calloc(BUFFER_SIZE, sizeof(*buffer));
	read_bytes = 0;
	if (string[0] == '\0')
		while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
			ft_strlcat(string, buffer, BUFFER_SIZE + 2);
	free(buffer);
	if ((n = ft_strchr(string, (int)'\n')))
	{
		ft_strlcpy(*line, string, n - string + 1);
		string = ft_strdup(++n);
		return (1);
	}
	else if (read_bytes == 0)
	{
		free(string);
		return (0);
	}
	else
	{
		free(string);
		return (-1);
	}
}
