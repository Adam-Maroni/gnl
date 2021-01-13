/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:37:08 by amaroni           #+#    #+#             */
/*   Updated: 2021/01/13 12:29:42 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	size_t	bytes_read;
	int		i;

	i = 0;
	*line = (char*)ft_calloc(10, sizeof(**line));
	while (!ft_memchr((void*)*line, (int)'\n', ft_strlen(*line))
			&& !ft_memchr((void*)*line, -1, ft_strlen(*line)))
		bytes_read = read(fd, *line, ++i);
	if (bytes_read > 0)
		return (1);
	else if (bytes_read == 0)
		return (0);
	else
		return (-1);
}
