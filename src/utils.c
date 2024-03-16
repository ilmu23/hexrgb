/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:48:29 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/16 05:02:52 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexrgb.h"

static inline char	**getvals(const char *val);

t_type	determinetype(const char *val)
{
	if (ishex(val))
		return (HEXV);
	if (isrgb(val))
		return (RGBV);
	return (ERR);
}

size_t	countchars(const char *s, const uint8_t c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		if (*s++ == c)
			n++;
	}
	return (n);
}

uint8_t	invalidchars(const char *val)
{
	if (*val == '#')
		val++;
	while (*val)
	{
		if (ft_isdigit(*val)
			|| (ft_toupper(*val) >= 'A' && ft_toupper(*val) <= 'F'))
			val++;
		else
			return (1);
	}
	return (0);
}

void	setcolor(const char *val, const t_type type)
{
	char	**vals;

	if (type == RGBV)
		vals = ft_pusharr(ft_split(ft_push((void *)val), ','));
	else
		vals = getvals(ft_push((void *)val));
	if (!vals)
		return ;
	ft_printf("\e[38;2;%u;%u;%um", ft_atou64(vals[0]),
		ft_atou64(vals[1]), ft_atou64(vals[2]));
	ft_popblks(5, val, vals, vals[0], vals[1], vals[2]);
}

static inline char	**getvals(const char *val)
{
	char	**out;

	out = ft_push(ft_calloc(4, sizeof(char *)));
	if (!out)
		return (NULL);
	if (*val == '#')
		val++;
	out[0] = ft_push(ft_utoa(ft_atou_base(ft_substr(val, 0, 2), HEX)));
	out[1] = ft_push(ft_utoa(ft_atou_base(ft_substr(val, 2, 2), HEX)));
	out[2] = ft_push(ft_utoa(ft_atou_base(ft_substr(val, 4, 2), HEX)));
	if (!out[0] || !out[1] || !out[2])
	{
		ft_popblks(4, out, out[0], out[1], out[2]);
		return (NULL);
	}
	return (out);
}
