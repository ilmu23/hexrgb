/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:06:35 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/11 18:41:53 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		neg;
	char	*out;
	size_t	i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	out = ft_calloc(ft_intlen(n) + 1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (n > 9)
	{
		out[i++] = n % 10 + '0';
		n /= 10;
	}
	out[i++] = n + '0';
	if (neg == 1)
		out[i] = '-';
	return (ft_strrev(out));
}
