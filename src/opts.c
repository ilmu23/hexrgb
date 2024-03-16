/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 04:30:29 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/16 09:38:29 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexrgb.h"

static void	getopts(char *optstr, t_opts *opts);

t_opts	parseopts(char **argv)
{
	t_opts	opts;

	ft_bzero(&opts, sizeof(t_opts));
	opts.type = ANY;
	opts.xcase = UPPER;
	opts.format = FULL;
	while (*argv)
	{
		if (ft_strequals(*argv, "-v"))
		{
			ft_printf("hexrgb-%s\n", VERSION);
			ft_exit(0);
		}
		if (**argv != '-')
			break ;
		getopts(*argv++ + 1, &opts);
		opts.optblks++;
	}
	return (opts);
}

static void	getopts(char *optstr, t_opts *opts)
{
	while (*optstr)
	{
		if (*optstr == 'c')
			opts->color = 1;
		else if (*optstr == 'h' && opts->type != RGBV)
			opts->type = HEXV;
		else if (*optstr == 'r' && opts->type != HEXV)
			opts->type = RGBV;
		else if (*optstr == 's')
			opts->format = SHORT;
		else if (*optstr == 'l')
			opts->xcase = LOWER;
		else if (*optstr == 'f')
			opts->input = INFILE;
		else if (*optstr == 'v')
			ft_dprintf(2, "hexrgb: can't combine '-v' with other options\n");
		else if (*optstr != 'h' && *optstr != 'r')
			ft_dprintf(2, "hexrgb: ignoring unrecognized option '-%c'\n",
				*optstr);
		optstr++;
	}
}
