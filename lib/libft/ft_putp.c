/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:08:43 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/20 19:31:49 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putleft(char *s, int ndigits, int *flags);
static int	putright(char *s, int ndigits, int *flags);
static char	*ptox(unsigned long n, int ndigits);

int	ft_putp(va_list args, int *flags)
{
	unsigned long	p;
	char			*s;
	int				out;
	int				ndigits;

	if (flags[3] > 0)
	{
		flags[1] = 0;
		ndigits = flags[3];
	}
	else
		ndigits = 0;
	p = va_arg(args, unsigned long);
	s = ptox(p, ndigits);
	if (!s)
		return (-1);
	if (flags[0] == 1)
		out = putleft(s, ndigits, flags);
	else
		out = putright(s, ndigits, flags);
	free(s);
	return (out);
}

static int	putleft(char *s, int ndigits, int *flags)
{
	int	slen;
	int	ret;
	int	out;

	out = 0;
	slen = ft_strlen(s);
	ret = putpadding(ndigits - slen, '0', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = ft_putstr_fd(s, 1);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = putpadding(flags[2] - (ndigits + slen), ' ', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	return (out);
}

static int	putright(char *s, int ndigits, int *flags)
{
	int	slen;
	int	ret;
	int	out;

	out = 0;
	slen = ft_strlen(s);
	if (ndigits < slen)
		ndigits = slen;
	if (flags[1] == 1)
		ret = putpadding(flags[2] - slen, '0', &flags[0], flags);
	else
		ret = putpadding(flags[2] - ndigits, ' ', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = putpadding(ndigits - slen, '0', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = ft_putstr_fd(s, 1);
	out += ret;
	if (ret < 0)
		return (-1);
	return (out);
}

static char	*ptox(unsigned long n, int ndigits)
{
	const char	hexarr[] = "0123456789abcdef";
	size_t		i;
	char		*tmp;
	char		*out;
	int			xlen;

	xlen = ft_hexlen(n);
	if (ndigits > xlen)
		tmp = ft_calloc(ndigits + 1, sizeof(char));
	else
		tmp = ft_calloc(xlen + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (n > 15)
	{
		tmp[i++] = hexarr[n % 16];
		n /= 16;
	}
	tmp[i++] = hexarr[n];
	ft_strrev(tmp);
	out = ft_strjoin("0x", tmp);
	free(tmp);
	return (out);
}
