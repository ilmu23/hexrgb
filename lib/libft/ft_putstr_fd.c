/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:26:57 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/03 19:46:58 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	out;
	int	ret;

	if (!s)
		return (ft_putstr_fd("(null)", fd));
	out = 0;
	while (*s)
	{
		ret = ft_putchar_fd(*s++, fd);
		if (ret < 0)
			return (-1);
		out += ret;
	}
	return (out);
}
