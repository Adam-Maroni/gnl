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
	static char	*reminder = NULL;
	char	*buffer;
	char	*tmp;
	char	*n;

	buffer = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(*buffer));
	if ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
		if(!(reminder = ft_strjoin(reminder, buffer)))
			return (-1);
	free(buffer);
	if (reminder[0])
	{
		if ((n = ft_strchr(reminder, (int)'\n')))
		{
			ft_strlcpy(*line, reminder, n - reminder + 1);
			tmp = reminder;
			if (++n)
				reminder = ft_strdup(n);
			free(tmp);
		}
		else
		{
			ft_strlcpy(*line, reminder, ft_strlen(reminder) + 1 );
			ft_bzero(reminder, ft_strlen(reminder));
		}
		return (1);
	}
	else if (read_bytes == 0)
	{
		free(reminder);
		return (0);
	}
	else
			return (-1);
}