/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:56:01 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/24 18:04:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	asize;
	size_t	i;

	asize = ft_strlen(s1) + 1;
	out = ft_calloc(asize, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (i < asize - 1)
	{
		out[i] = s1[i];
		i++;
	}
	return (out);
}
