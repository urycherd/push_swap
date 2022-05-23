/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:49:12 by urycherd          #+#    #+#             */
/*   Updated: 2022/01/25 13:28:19 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*nlist;

	if (!lst)
		return (0);
	nlist = ft_lstnew(f(lst->content));
	if (!nlist)
	{
		ft_lstclear(&nlist, del);
		return (0);
	}
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&nlist, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (nlist);
}
