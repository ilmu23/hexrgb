/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexrgb.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:05:16 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/16 10:22:47 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXRGB_H
# define HEXRGB_H
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

# define SGR_BOLDRON "\e[1;31m"
# define SGR_ULINEON "\e[4m"
# define SGR_RESET "\e[m"

# define VERSION "1.0"

typedef enum e_type
{
	HEXV,
	RGBV,
	ANY,
	ERR
}	t_type;

typedef enum e_vase
{
	UPPER,
	LOWER
}	t_case;

typedef enum e_input
{
	DEFAULT,
	INFILE
}	t_input;

typedef enum e_format
{
	FULL,
	SHORT
}	t_format;

typedef struct s_opts
{
	t_type		type;
	t_case		xcase;
	t_input		input;
	t_format	format;
	uint8_t		color;
	size_t		optblks;
}	t_opts;

// opts.c
t_opts	parseopts(char **argv);

// valid.c
uint8_t	isvalid(const char *val, const t_type type);
uint8_t	ishex(const char *val);
uint8_t	isrgb(const char *val);

// utils.c
t_type	determinetype(const char *val);
size_t	countchars(const char *s, const uint8_t c);
uint8_t	invalidchars(const char *val);
void	setcolor(const char *val, const t_type type);

// error.c
void	printerror(const char *val, const t_type type);

#endif
