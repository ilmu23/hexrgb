/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:43:58 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/20 19:46:39 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char		buf[499][BUFFER_SIZE + 1];
	int				rv;
	char			*out;

	out = NULL;
	rv = read(fd, NULL, 0);
	while (rv >= 0 && fd < 500)
	{
		if (*buf[fd])
		{
			if (bufcopy(buf[fd], &out) == NULL)
				return (NULL);
		}
		if (out)
		{
			if (out[ft_strclen(out, '\0') - 1] == '\n')
				return (out);
		}
		rv = read(fd, buf[fd], BUFFER_SIZE);
		if (rv < 1)
			break ;
	}
	if (fd >= 0 && fd < 500 && rv < 0)
		return (bufshift(buf[fd], buf[fd], 0));
	return (out);
}
