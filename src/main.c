/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:07:15 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/20 18:41:10 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexrgb.h"

int	main(int argc, char **argv)
{
	t_color	*color;
	char	*out;

	color = malloc(sizeof(t_color));
	if (!color)
		return (1);
	parseargs(argc, argv, color);
	out = convert(color);
	if (argc == 2 && *argv[1] == '-')
		free(color->value);
	else if (argc == 1)
		free(color->value);
	free(color);
	if (!out)
		return (1);
	printf("%s\n", out);
	free(out);
	return (0);
}

void	parseargs(int argc, char **argv, t_color *color)
{
	if (argc == 3)
		color->value = argv[2];
	else
		color->value = NULL;
	if (argc > 1)
	{
		if (*argv[1] == '-')
			color->type = argv[1][1];
		else
		{
			color->type = 'h';
			color->value = argv[1];
		}
	}
	else
		color->type = 'h';
}
