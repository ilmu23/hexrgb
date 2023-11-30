/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:37:25 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/20 18:41:46 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	out;
	long	prev;
	int		n;

	n = 1;
	out = 0;
	while (ft_isspace(*str) != 0)
		str++;
	if (*str == '-')
		n = -n;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) != 0)
	{
		prev = out;
		out = out * 10 + (*str - '0');
		if (out < prev)
		{
			if (n < 0)
				return (0);
			return (-1);
		}
		str++;
	}
	return (out * n);
}
