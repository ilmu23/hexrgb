/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:30:43 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/28 14:18:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	out;
	int	ret;

	if (!s)
	{
		ft_putendl_fd("(null)", fd);
		return (-1);
	}
	ret = ft_putstr_fd(s, fd);
	if (ret < 0)
		return (-1);
	out = ret;
	ret = ft_putchar_fd('\n', fd);
	if (ret < 0)
		return (-1);
	return (out + ret);
}
