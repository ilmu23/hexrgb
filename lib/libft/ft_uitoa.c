/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:22:58 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/11 18:42:38 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	size_t	i;
	char	*out;

	out = ft_calloc(ft_uintlen(n) + 1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (n > 9)
	{
		out[i++] = n % 10 + '0';
		n /= 10;
	}
	out[i] = n + '0';
	return (ft_strrev(out));
}
