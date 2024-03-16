/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:28:19 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/16 05:03:22 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexrgb.h"

static void	printhexerr(const char *val);
static void	printrgberr(const char *val);
static void	missingvals(char **vals);
static void	extravals(char **vals);

void	printerror(const char *val, const t_type type)
{
	ft_dprintf(2, "hexrgb: ");
	if (type == HEXV && isrgb(val))
		ft_dprintf(2, "%s: passing RGB value as hex\n", val);
	else if (type == RGBV && ishex(val))
		ft_dprintf(2, "%s: passing hex value as RGB\n", val);
	else if (type == HEXV)
		printhexerr(val);
	else if (type == RGBV)
		printrgberr(val);
	else if (!ft_strchr(val, ','))
		printhexerr(val);
	else
		printrgberr(val);
}

static void	printhexerr(const char *val)
{
	size_t	len;

	len = ft_strlen(val);
	if (invalidchars(val))
	{
		while (*val)
		{
			if (!ft_isdigit(*val) && (ft_toupper(*val) < 'A'
					|| ft_toupper(*val) > 'F') && *val != '#')
				ft_dprintf(2, "%s%c%s", SGR_BOLDRON, *val++, SGR_RESET);
			else
				ft_dprintf(2, "%c", *val++);
		}
		ft_dprintf(2, ": invalid characters\n");
	}
	else if (len < 6 + (*val == '#'))
		ft_dprintf(2, "%s%s%*s%s: not enough characters\n", val, SGR_ULINEON,
			6 + (*val == '#') - len, "", SGR_RESET);
	else
		ft_dprintf(2, "%.*s%s%s%s: too many characters\n", 6 + (*val == '#'),
			val, SGR_BOLDRON, &val[6 + (*val == '#')], SGR_RESET);
}

static void	printrgberr(const char *val)
{
	char	**vals;
	size_t	values;

	vals = ft_split(val, ',');
	values = (ft_getblksize(vals) / sizeof(char *)) - 1;
	if (values == 3)
	{
		while (*vals)
		{
			if (!ft_isuint(*vals, sizeof(uint8_t)))
				ft_dprintf(2, "%s%s%s", SGR_BOLDRON, *vals++, SGR_RESET);
			else
				ft_dprintf(2, "%s", *vals++);
			if (*vals)
				ft_putchar_fd(',', 2);
		}
		ft_dprintf(2, ": value out of range [0-255]\n");
	}
	else if (countchars(val, ',') == 2)
		ft_dprintf(2, "%s: empty fields\n", val);
	else if (values < 3)
		missingvals(vals);
	else
		extravals(vals);
}

static void	missingvals(char **vals)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		if (*vals)
			ft_dprintf(2, "%s", *vals++);
		else
			ft_dprintf(2, "%s%3s%s", SGR_ULINEON, "", SGR_RESET);
		if (++i < 3)
			ft_putchar_fd(',', 2);
	}
	ft_dprintf(2, ": missing values\n");
}

static void	extravals(char **vals)
{
	size_t	i;

	i = 0;
	while (*vals)
	{
		if (i++ < 3)
			ft_dprintf(2, "%s", *vals++);
		else
			ft_dprintf(2, "%s%s%s", SGR_BOLDRON, *vals++, SGR_RESET);
		if (*vals)
			ft_putchar_fd(',', 2);
	}
	ft_dprintf(2, ": extra values\n");
}
