/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:05:38 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/30 09:05:58 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitox(unsigned int n)
{
	const char	*hexarr = "0123456789abcdef";
	char		*out;
	size_t		i;

	out = ft_calloc(ft_hexlen((unsigned long)n), sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (n > 15)
	{
		out[i++] = hexarr[n % 16];
		n /= 16;
	}
	out[i] = hexarr[n];
	return (ft_strrev(out));
}
