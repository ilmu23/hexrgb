/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:59:42 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/27 20:59:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	out;

	out = 0;
	if (!lst)
		return (out);
	while (lst->next)
	{
		lst = lst->next;
		out++;
	}
	out++;
	return (out);
}
