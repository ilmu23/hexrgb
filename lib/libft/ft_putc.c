/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:13:44 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/20 19:31:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putc(va_list args, int *flags, char format)
{
	char	c;
	int		rv1;
	int		rv2;

	rv1 = 0;
	if (format == '%')
		c = '%';
	else
		c = va_arg(args, int);
	if (flags[0] == 0)
		rv1 = putpadding(flags[2] - 1, ' ', &flags[0], flags);
	if (rv1 < 0)
		return (-1);
	rv2 = ft_putchar_fd(c, 1);
	if (rv2 < 0)
		return (-1);
	if (flags[0] == 1)
		rv1 = putpadding(flags[2] - 1, ' ', &flags[0], flags);
	if (rv1 < 0)
		return (-1);
	return (rv1 + rv2);
}
