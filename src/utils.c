/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:48:29 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/20 19:47:52 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexrgb.h"

int	hextoi(char *value)
{
	int	out;

	if (isupper(*value) > 0)
		*value += 32;
	if (isupper(*(value + 1)) > 0)
		*(value + 1) += 32;
	if (isdigit(*value) > 0)
		out = *value - '0';
	else if (*value > 96 && *value < 103)
		out = *value - 87;
	else
		return (0);
	value++;
	out = out * 16;
	if (isdigit(*value) > 0)
		out += *value - '0';
	else if (*value > 96 && *value < 103)
		out += *value - 87;
	else
		return (0);
	return (out);
}

char	**itohex(char **rgb)
{
	size_t	i;
	size_t	j;
	int		value;

	if (!rgb)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		j = 0;
		value = 0;
		while (rgb[i][j])
		{
			value = value * 10;
			value += rgb[i][j++] - '0';
		}
		free(rgb[i]);
		rgb[i++] = ft_uitox((unsigned int)value);
	}
	return (rgb);
}

char	*getinput(int type)
{
	char	*out;
	int		rv;

	if (type == 1)
	{
		out = calloc(9, sizeof(char));
		if (!out)
			return (NULL);
		if (read(0, out, 7) < 0)
			return (NULL);
	}
	else
	{
		out = calloc(12, sizeof(char));
		if (!out)
			return (NULL);
		rv = read(0, out, 11);
		if (rv == -1)
			return (NULL);
		out[rv - 1] = '\0';
	}
	return (out);
}
