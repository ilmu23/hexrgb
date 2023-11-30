/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:59:33 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/27 20:59:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	out = NULL;
	while (lst->next)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&out, del);
			return (NULL);
		}
		ft_lstadd_back(&out, new);
		lst = lst->next;
	}
	new = ft_lstnew(f(lst->content));
	if (!new)
	{
		ft_lstclear(&out, del);
		return (NULL);
	}
	ft_lstadd_back(&out, new);
	return (out);
}
