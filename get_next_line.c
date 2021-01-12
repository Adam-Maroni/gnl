/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:37:08 by amaroni           #+#    #+#             */
/*   Updated: 2021/01/11 12:00:49 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int	get_next_line(int fd, char **line)
{
	int sz;
	
	if ((sz = read(fd, *line, ft_strlen(*line))) < 0)
	{
		printf("Problem\n");
		return (-1);
	}
	{
		(*line)[sz] = '\0';
		printf("%s\n", *line);
		return 1;
	}
	else
		return -1;
}