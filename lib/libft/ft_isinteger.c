/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:32:59 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/20 18:36:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinteger(char *n)
{
	size_t	i;
	long	nbr;

	i = 0;
	while (n[i])
	{
		if (ft_isdigit(n[i]) == 0 && (n[i] != '-' || n[i] != '+'))
			return (0);
		i++;
	}
	nbr = ft_atol(n);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}
