/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:06:35 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/20 19:45:58 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexrgb.h"

char	*convert(t_color *color)
{
	if (!(color->value))
	{
		if (color->type == 'h')
		{
			color->value = getinput(1);
			if (!(color->value))
				return (NULL);
		}
		else
		{
			color->value = getinput(2);
			if (!(color->value))
				return (NULL);
		}
	}
	if (color->type == 'r')
		return (rgbtohex(color->value));
	return (hextorgb(color->value));
}

char	*hextorgb(char *value)
{
	size_t	i;
	char	*tmp;
	char	*out;
	char	**rgb;

	out = calloc(12, sizeof(char));
	if (!out)
		return (NULL);
	rgb = getvalues(value);
	if (!rgb)
	{
		free(out);
		return (NULL);
	}
	i = 0;
	tmp = out;
	while (i < 3)
	{
		tmp = stpcpy(tmp, rgb[i]);
		if (i < 2)
			*tmp++ = ',';
		free(rgb[i++]);
	}
	free(rgb);
	return (out);
}

char	*rgbtohex(char *value)
{
	size_t	i;
	char	*tmp;
	char	*out;
	char	**rgb;

	rgb = itohex(ft_split(value, ','));
	if (!rgb)
		return (NULL);
	out = calloc(8, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	*out = '#';
	tmp = out + 1;
	while (i < 3)
	{
		tmp = stpcpy(tmp, rgb[i]);
		free(rgb[i++]);
	}
	free(rgb);
	return (out);
}

char	**getvalues(char *value)
{
	size_t	i;
	char	**out;

	if (*value == '#')
		value++;
	out = malloc(4 * sizeof(char *));
	if (!out)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		out[i] = ft_itoa(hextoi(value + (i * 2)));
		i++;
	}
	return (out);
}
