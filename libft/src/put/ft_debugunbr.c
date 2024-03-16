/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:18:19 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 13:31:49 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_put.h"

void	ft_debugunbr(unsigned long n)
{
	if (n > 9)
	{
		ft_debugunbr(n / 10);
		ft_putchar_fd(n % 10 + '0', DEBUGFD);
		return ;
	}
	ft_putchar_fd(n + '0', DEBUGFD);
}
