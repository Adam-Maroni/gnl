/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:37:08 by amaroni           #+#    #+#             */
/*   Updated: 2021/01/12 12:00:15 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	int	bytes_read;

	bytes_read = read(fd, *line, 20);
	if (bytes_read > 0)
	{
		(*line)[bytes_read] = '\0';
		printf("%s", *line);
		return (1);
	}
	else if (bytes_read == 0)
	{
		printf("Reach EOF\n");
		return (0);
	}
	else
	{
		printf("problem!\n");
		return (-1);
	}
}
