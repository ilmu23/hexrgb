/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:44:11 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/20 19:44:34 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*bufshift(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	src = dst + n;
	while (*src)
		*src++ = '\0';
	if (*dst)
		return (dst);
	return (NULL);
}

char	*bufcopy(char *buf, char **out)
{
	size_t	i;
	size_t	linelen;
	size_t	buflen;
	char	*cpy;
	char	*tmp;

	buflen = ft_strclen(buf, '\0');
	linelen = ft_strclen(buf, '\n');
	if (linelen < buflen)
		linelen++;
	cpy = ft_calloc(linelen + 1, sizeof(char));
	i = 0;
	while (cpy && i < linelen)
	{
		cpy[i] = buf[i];
		i++;
	}
	bufshift(buf, &buf[linelen], buflen - linelen);
	tmp = ft_strjoin(*out, cpy);
	free(*out);
	if (!cpy)
		return (NULL);
	free(cpy);
	*out = tmp;
	return (buf);
}
