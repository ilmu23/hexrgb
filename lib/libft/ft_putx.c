/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:09:20 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/20 19:32:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(unsigned int n, int *ndigits, int *flags);
static int	putleft(unsigned int n, int ndigits, int *flags, int upper);
static int	putright(unsigned int n, int ndigits, int *flags, int upper);

int	ft_putx(va_list args, int *flags, char format)
{
	unsigned int	n;
	int				ndigits;
	int				upper;

	upper = 0;
	if (flags[3] > 0)
		ndigits = flags[3];
	else
		ndigits = 0;
	n = va_arg(args, unsigned int);
	if (format == 'X')
		upper = 1;
	if (upper == 1 && flags[4] == 1)
		flags[4] = 2;
	if (n == 0)
		flags[4] = 0;
	if (flags[0] == 1)
		return (putleft(n, ndigits, flags, upper));
	return (putright(n, ndigits, flags, upper));
}

static int	putleft(unsigned int n, int ndigits, int *flags, int upper)
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
		ret = ft_putxnbr_fd(n, 1, upper);
		out += ret;
	}
	if (ret < 0)
		return (-1);
	ret = putpadding(flags[2] - out, ' ', &flags[0], flags);
	if (ret < 0)
		return (-1);
	return (out + ret);
}

static int	putright(unsigned int n, int ndigits, int *flags, int upper)
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
	ret = putpadding(ndigits - nlen, '0', &flags[0], flags);
	out += ret;
	if (ret >= 0)
		ret = 0;
	if ((flags[3] != 0 || n != 0) && ret == 0)
		ret = ft_putxnbr_fd(n, 1, upper);
	if (ret < 0)
		return (-1);
	return (out + ret);
}

static int	getlen(unsigned int n, int *ndigits, int *flags)
{
	int	digits;

	digits = ft_hexlen((unsigned long)n);
	if (flags[2] > *ndigits && flags[4] > 0)
		digits += 2;
	if (flags[2] > *ndigits && flags[4] > 0 && n != 0)
		*ndigits += 2;
	if (flags[0] == 0 && flags[2] > 0 && digits > *ndigits)
		if (flags[3] != 0 || n > 0)
			*ndigits = digits;
	return (digits);
}
