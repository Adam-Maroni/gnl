/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:22:33 by amaroni           #+#    #+#             */
/*   Updated: 2021/01/16 08:31:45 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned long rt;

	rt = 0;
	while (*(s + rt) != '\0')
		rt++;
	return (rt);
}

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((char*)s + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rt_pointer;

	if ((rt_pointer = (void*)malloc(nmemb * size)) == NULL)
		return (NULL);
	ft_bzero(rt_pointer, nmemb * size);
	return (rt_pointer);
}

char	*ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	while ((*(s + i) != (char)c) && (*(s + i) != '\0'))
		i++;
	if (*(s + i) == (char)c)
		return (s + i);
	else
		return (NULL);
}

char	*ft_strdup(char *s)
{
	char		*rt_pointer;
	size_t		i;

	if ((rt_pointer = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))) == NULL)
	{
		free(rt_pointer);
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		rt_pointer[i] = s[i];
		i++;
	}
	rt_pointer[i] = '\0';
	return (rt_pointer);
}

size_t		ft_strlcat(char *dst, char *src, size_t size)
{
	size_t i;
	size_t y;
	size_t rt;

	i = 0;
	y = ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	rt = ft_strlen(dst) + ft_strlen(src);
	while (src[i] && y < (size - 1))
	{
		dst[y] = src[i];
		y++;
		i++;
	}
	*(dst + y) = '\0';
	return (rt);
}

size_t		ft_strlcpy(char *dst, char *src, size_t size)
{
	unsigned long y;

	y = ft_strlen(src);
	if (size <= 0)
		return (y);
	while ((size-- > 1) && (*src))
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (y);
}
