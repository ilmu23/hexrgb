/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:57:12 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 05:10:50 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isupper.c
 */

#include "lft_is.h"

/** @brief Checks if c is an uppercase character
 *
 * @param c Character to check
 * @retval uint8_t 1 if c is uppercase, 0 if not
 */
uint8_t	ft_isupper(uint8_t c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
