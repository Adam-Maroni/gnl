/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:55:20 by amaroni           #+#    #+#             */
/*   Updated: 2021/01/11 12:00:53 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int	get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
#endif
