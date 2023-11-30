/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:26:06 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/20 19:32:02 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putleft(unsigned int n, int ndigits, int *flags);
static int	putright(unsigned int n, int ndigits, int *flags);
static int	getlen(unsigned int n, int *ndigits, int *flags);

int	ft_putu(va_list args, int *flags)
{
	unsigned int	n;
	int				ndigits;

	if (flags[3] > 0)
	{
		flags[1] = 0;
		ndigits = flags[3];
	}
	else
		ndigits = 0;
	n = va_arg(args, unsigned int);
	if (flags[0] == 1)
		return (putleft(n, ndigits, flags));
	return (putright(n, ndigits, flags));
}

static int	putleft(unsigned int n, int ndigits, int *flags)
{
	int	nlen;
	int	ret;
	int	out;

	out = 0;
	nlen = getlen(n, &ndigits, flags);
	ret = putpadding(ndigits - nlen, '0', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	if (flags[3] != 0 || n != 0)
	{
		ret = ft_putunbr_fd(n, 1);
		out += ret;
	}
	if (ret < 0)
		return (-1);
	ret = putpadding(flags[2] - out, ' ', &flags[0], flags);
	if (ret < 0)
		return (-1);
	return (out + ret);
}

static int	putright(unsigned int n, int ndigits, int *flags)
{
	int	nlen;
	int	ret;
	int	out;

	out = 0;
	nlen = getlen(n, &ndigits, flags);
	if (flags[1] == 1)
		ret = putpadding(flags[2] - ndigits, '0', &flags[0], flags);
	else
		ret = putpadding(flags[2] - ndigits, ' ', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	if (flags[1] == 0)
	{
		ret = putpadding(ndigits - nlen, '0', &flags[0], flags);
		out += ret;
	}
	if (ret >= 0)
		ret = 0;
	if ((flags[3] != 0 || n != 0) && ret == 0)
		ret = ft_putunbr_fd(n, 1);
	if (ret < 0)
		return (-1);
	return (out + ret);
}

static int	getlen(unsigned int n, int *ndigits, int *flags)
{
	int	digits;

	digits = ft_uintlen(n);
	if (flags[1] == 1 && flags[5] > 0 && n == 0)
		digits++;
	if (flags[0] == 0 && flags[5] > 0)
		digits++;
	else if (flags[0] == 1 && flags[2] == 0 && flags[5] > 0
		&& digits <= *ndigits)
		digits++;
	if (flags[0] == 0 && flags[2] > 0 && digits > *ndigits)
	{
		if (flags[3] != 0 || n > 0)
			*ndigits = digits;
	}
	else if (flags[5] > 0 && flags[0] == 1 && digits > *ndigits
		&& flags[2] > 0)
		*ndigits = digits;
	if (flags[5] > 0 && flags[2] == 0 && digits > *ndigits)
		digits = *ndigits + 1;
	else if (flags[5] > 0 && digits > *ndigits)
		*ndigits = digits;
	return (digits);
}
