/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:07:19 by urycherd          #+#    #+#             */
/*   Updated: 2022/01/27 15:52:08 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **list_a, int i)
{
	t_list	*node_to_move;

	if (*list_a == NULL)
		return ;
	node_to_move = *list_a;
	*list_a = node_to_move->next;
	ft_lstadd_back(list_a, node_to_move);
	node_to_move->next = NULL;
	if (i != 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **list_b, int i)
{
	t_list	*node_to_move;

	if (*list_b == NULL)
		return ;
	node_to_move = *list_b;
	*list_b = node_to_move->next;
	ft_lstadd_back(list_b, node_to_move);
	node_to_move->next = NULL;
	if (i != 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **list_a, t_list **list_b)
{
	ft_ra(list_a, 0);
	ft_rb(list_b, 0);
	write(1, "rr\n", 3);
}
