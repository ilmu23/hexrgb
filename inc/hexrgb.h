/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexrgb.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:05:16 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/20 20:14:12 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXRGB_H
# define HEXRGB_H
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

typedef struct s_color {
	char	type;
	char	*value;
}	t_color;

// main.c
void	parseargs(int argc, char **argv, t_color *color);

// convert.c
char	**getvalues(char *value);
char	*convert(t_color *color);
char	*hextorgb(char *value);
char	*rgbtohex(char *value);

// utils.c
char	*getinput(int type);
char	**itohex(char **rgb);
int		hextoi(char *value);

#endif
