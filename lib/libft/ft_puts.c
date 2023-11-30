/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:30:19 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/20 19:31:54 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putleft(char *s, int nchars, int *flags);
static int	putright(char *s, int nchars, int *flags);

int	ft_puts(va_list args, int *flags)
{
	const char	nullstr[7] = "(null)\0";
	char		*s;
	int			nchars;
	int			slen;

	s = va_arg(args, char *);
	if (!s)
		s = (char *)nullstr;
	slen = (int)ft_strlen(s);
	if (flags[3] == 0)
		nchars = 0;
	else if (flags[3] > 0 && flags[3] <= slen)
		nchars = flags[3];
	else
		nchars = slen;
	if (nchars == 0 && flags[2] == 0)
		return (0);
	if (flags[0] == 1)
		return (putleft(s, nchars, flags));
	return (putright(s, nchars, flags));
}

static int	putleft(char *s, int nchars, int *flags)
{
	int	ret;
	int	out;

	out = 0;
	ret = 0;
	while (out < nchars && ret >= 0)
	{
		ret = ft_putchar_fd(s[out], 1);
		out += ret;
	}
	if (ret < 0)
		return (-1);
	ret = putpadding(flags[2] - nchars, ' ', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	return (out);
}

static int	putright(char *s, int nchars, int *flags)
{
	int	ret;
	int	out;
	int	i;

	i = 0;
	out = 0;
	ret = putpadding(flags[2] - nchars, ' ', &flags[0], flags);
	out += ret;
	while (i < nchars && ret >= 0)
	{
		ret = ft_putchar_fd(s[i++], 1);
		out += ret;
	}
	if (ret < 0)
		return (-1);
	return (out);
}
