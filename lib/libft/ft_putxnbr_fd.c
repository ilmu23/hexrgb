/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:37:45 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/08 18:37:18 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putxnbr_fd(unsigned int n, int fd, int upper)
{
	const char	hexarr[] = {'0', '1', '2', '3', '4', '5',
		'6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	int			ret;
	int			out;

	out = 0;
	if (n > 15)
	{
		ret = ft_putxnbr_fd(n / 16, fd, upper);
		out += ret;
		if (upper == 0)
			ret = ft_putchar_fd(hexarr[n % 16], fd);
		else
			ret = ft_putchar_fd(ft_toupper(hexarr[n % 16]), fd);
		if (ret < 0 || out < 1)
			return (-1);
		return (out + ret);
	}
	if (upper == 0)
		return (ft_putchar_fd(hexarr[n % 16], fd));
	return (ft_putchar_fd(ft_toupper(hexarr[n % 16]), fd));
}
