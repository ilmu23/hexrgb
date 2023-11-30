/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:02:23 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/27 20:52:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getsplits(const char *s, char c);
static char		**checktab(char **out, size_t splits);
static char		*skipdelims(const char *s, char c);
static char		*makesplit(const char **s, char c);

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	splits;
	size_t	i;

	if (!s)
		return (NULL);
	if (*s == c && c != '\0')
		s = skipdelims(s, c);
	splits = getsplits(s, c);
	out = malloc((splits + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	if (splits == 0 || (splits == 1 && c == '\0' && !(*s)))
	{
		out[0] = NULL;
		return (out);
	}
	i = 0;
	while (i < splits && *s)
		out[i++] = makesplit(&s, c);
	out[i] = NULL;
	return (checktab(out, splits));
}

static char	**checktab(char **out, size_t splits)
{
	size_t	i;

	i = 0;
	while (i < splits)
	{
		if (!out[i++])
		{
			i--;
			break ;
		}
	}
	if (i == splits)
		return (out);
	i = 0;
	while (i < splits)
	{
		if (out[i])
			free(out[i]);
		i++;
	}
	free(out);
	return (NULL);
}

static char	*makesplit(const char **s, char c)
{
	const char	*tmp;
	char		*buf;
	char		*out;
	size_t		i;

	buf = ft_calloc(ft_strlen(*s) + 1, sizeof(char));
	if (!buf)
		return (NULL);
	i = 0;
	tmp = *s;
	while (*tmp)
	{
		if (*tmp == c)
			break ;
		buf[i++] = *tmp++;
	}
	tmp = skipdelims(tmp, c);
	*s = tmp;
	out = ft_strdup(buf);
	free(buf);
	if (!out)
		return (NULL);
	return (out);
}

static size_t	getsplits(const char *s, char c)
{
	size_t	out;

	if (!(*s))
		return (0);
	out = 1;
	if (!c)
		return (out);
	while (*s)
	{
		if (*s == c)
		{
			out++;
			s = skipdelims(s, c);
			if (!(*s))
				out--;
			continue ;
		}
		s++;
	}
	return (out);
}

static char	*skipdelims(const char *s, char c)
{
	while (*s == c)
		s++;
	return ((char *)s);
}
