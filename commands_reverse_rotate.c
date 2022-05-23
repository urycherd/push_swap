/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:00:57 by urycherd          #+#    #+#             */
/*   Updated: 2022/02/15 14:33:35 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **list_a, int i)
{
	t_list	*last_list;
	t_list	*penultimate_list;

	if (*list_a == NULL)
		return ;
	last_list = ft_lstlast(*list_a);
	penultimate_list = *list_a;
	while (penultimate_list->next->next)
		penultimate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	ft_lstadd_front(list_a, last_list);
	if (i != 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **list_b, int i)
{
	t_list	*last_list;
	t_list	*penultimate_list;

	if (*list_b == NULL)
		return ;
	last_list = ft_lstlast(*list_b);
	penultimate_list = *list_b;
	while (penultimate_list->next->next)
		penultimate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	ft_lstadd_front(list_b, last_list);
	if (i != 0)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **list_a, t_list **list_b)
{
	ft_rra(list_a, 0);
	ft_rrb(list_b, 0);
	write(1, "rrr\n", 4);
}
