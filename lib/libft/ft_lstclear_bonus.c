/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:59:10 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/27 20:59:13 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;

	if (!lst)
		return ;
	if (!(*lst) || !del)
		return ;
	while ((*lst)->next)
	{
		del((*lst)->content);
		last = *lst;
		*lst = (*lst)->next;
		free(last);
	}
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
