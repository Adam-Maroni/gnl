/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:37:08 by amaroni           #+#    #+#             */
/*   Updated: 2021/01/16 17:08:18 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

int	get_next_line(int fd, char **line)
{
	size_t		read_bytes;
	char		*buffer;
	static char	*string = NULL;
	char		*tmp;
	char		*n;

	read_bytes = 0;
	buffer = (char*)ft_calloc(BUFFER_SIZE, sizeof(*buffer));
	if (!string)
		while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
			if (!(string = ft_strjoin(string, buffer)))
				return (-1);
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
