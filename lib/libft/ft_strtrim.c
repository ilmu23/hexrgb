/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:00:57 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/20 19:25:28 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getasize(const char *s, const char *set, size_t *range);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	size_t	range[2];
	size_t	asize;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	if (!(*s1))
		asize = 1;
	else
		asize = getasize(s1, set, range);
	out = ft_calloc(asize, sizeof(char));
	if (!out)
		return (NULL);
	if (asize == 1)
	{
		*out = '\0';
		return (out);
	}
	i = 0;
	while (range[0] <= range[1])
		out[i++] = s1[range[0]++];
	return (out);
}

static size_t	getasize(const char *s, const char *set, size_t *range)
{
	range[0] = 0;
	range[1] = ft_strlen(s) - 1;
	while (ft_contains(set, s[range[0]]) == 1)
		range[0]++;
	while (ft_contains(set, s[range[1]]) == 1 && range[1] > range[0])
		range[1]--;
	return (range[1] - range[0] + 2);
}
