/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:07:15 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/16 09:59:49 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexrgb.h"

static void	interactive(const t_opts opts, const char *fname, int32_t fd);
static void	convert(char *val, t_opts opts);
static void	torgb(const char *val, t_opts opts);
static void	tohex(const char *val, t_opts opts);

int	main(int argc, char **argv)
{
	t_opts		opts;
	int32_t		fd;

	opts = parseopts(&argv[1]);
	argv += opts.optblks;
	if (opts.input == INFILE && argv[1])
	{
		while (argv[1])
		{
			fd = open(argv++[1], O_RDONLY);
			if (fd < 0)
				ft_dprintf(2, "hexrgb: %s: %s\n", argv[0],
					ft_strlower(ft_strdup(strerror(errno))));
			else
				interactive(opts, argv[0], fd);
		}
	}
	else if (!argv[1])
		interactive(opts, NULL, 0);
	while (argv[1])
		convert(argv++[1], opts);
	return (ft_return(0));
	(void)argc;
}

static void	interactive(const t_opts opts, const char *fname, int32_t fd)
{
	char	*val;
	t_opts	curopts;

	curopts = opts;
	if (fname && opts.format == FULL)
		ft_printf("// %s \\\\\n", fname);
	else if (fname)
		ft_printf("%s:\n", fname);
	val = ft_strtrim(get_next_line(fd), "\t\n\v\f\r ");
	while (val)
	{
		if (opts.type == ANY)
			curopts.type = determinetype(val);
		convert(val, curopts);
		val = ft_strtrim(get_next_line(fd), "\t\n\v\f\r ");
	}
	if (fname && opts.format == FULL)
		ft_printf("\\\\ %s //\n", fname);
	if (fd)
		close(fd);
}

static void	convert(char *val, t_opts opts)
{
	if (opts.type == ANY)
		opts.type = determinetype(val);
	if (!isvalid(val, opts.type))
		return ;
	if (opts.color)
		setcolor(val, opts.type);
	if (opts.type == HEXV)
		torgb(val, opts);
	else
		tohex(val, opts);
	if (opts.color)
		ft_printf("%s\n", SGR_RESET);
	else
		ft_putchar_fd('\n', 1);
}

static void	torgb(const char *val, t_opts opts)
{
	static const char	edge[2][3] = {"((", "))"};
	static size_t		i = 0;
	size_t				offset;

	offset = 0 + (*val == '#');
	if (opts.format == FULL)
		ft_printf("%s %s ---> ", edge[i++], val);
	ft_printf("%u,%u,%u",
		ft_atou_base(ft_push(ft_substr(val, 0 + offset, 2)), HEX),
		ft_atou_base(ft_push(ft_substr(val, 2 + offset, 2)), HEX),
		ft_atou_base(ft_push(ft_substr(val, 4 + offset, 2)), HEX));
	ft_popn(3);
	i %= 2;
}

static void	tohex(const char *val, t_opts opts)
{
	static const char	edge[2][3] = {"((", "))"};
	static size_t		i = 0;
	char				**vals;

	vals = ft_pusharr(ft_split(ft_push((void *)val), ','));
	if (opts.format == FULL)
		ft_printf("%s %s ---> ", edge[i++], val);
	if (opts.xcase == UPPER)
	{
		ft_printf("#%s%s%s",
				ft_push(ft_utoa_base(ft_atou64(vals[0]), HEX)),
				ft_push(ft_utoa_base(ft_atou64(vals[1]), HEX)),
				ft_push(ft_utoa_base(ft_atou64(vals[2]), HEX)));
	}
	else
	{
		ft_printf("#%s%s%s",
				ft_push(ft_strlower(ft_utoa_base(ft_atou64(vals[0]), HEX))),
				ft_push(ft_strlower(ft_utoa_base(ft_atou64(vals[1]), HEX))),
				ft_push(ft_strlower(ft_utoa_base(ft_atou64(vals[2]), HEX))));
	}
	ft_popn(8);
	i %= 2;
}
