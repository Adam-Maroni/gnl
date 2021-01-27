/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:22:33 by amaroni           #+#    #+#             */
/*   Updated: 2021/01/27 09:40:36 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}
