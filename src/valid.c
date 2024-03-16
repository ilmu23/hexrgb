/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:58:45 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/16 07:12:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexrgb.h"

uint8_t	isvalid(const char *val, const t_type type)
{
	uint8_t	rv;

	rv = 0;
	if (type == HEXV)
		rv = ishex(val);
	else if (type == RGBV)
		rv = isrgb(val);
	if (type == ERR || rv == 0)
		printerror(val, type);
	return (rv);
}

uint8_t	ishex(const char *val)
{
	if (*val == '#')
		val++;
	if (ft_strlen(val) != 6)
		return (0);
	if (!ft_isuint_base(val, sizeof(uint32_t), HEX)
		|| *val == '+' || *val == '-')
		return (0);
	return (1);
}

uint8_t	isrgb(const char *val)
{
	char	**vals;

	vals = ft_split(val, ',');
	if (!vals)
	{
		ft_dprintf(2, "hexrgb: %s\n", ft_strlower(ft_strdup(strerror(errno))));
		ft_exit(1);
	}
	if (ft_getblksize(vals) != sizeof(char *) * 4)
		return (0);
	while (*vals)
	{
		if (!ft_isuint(*vals, sizeof(uint8_t))
			|| **vals == '+' || **vals == '-')
			return (0);
		vals++;
	}
	return (1);
}
