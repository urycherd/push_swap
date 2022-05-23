/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:24:22 by urycherd          #+#    #+#             */
/*   Updated: 2022/02/14 14:58:47 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **list_a, int i)
{
	t_list	*node_to_move;
	t_list	*new_start;

	node_to_move = *list_a;
	if (*list_a == NULL || (*list_a)->next == NULL)
		return ;
	*list_a = node_to_move->next;
	new_start = *list_a;
	node_to_move->next = new_start->next;
	new_start->next = node_to_move;
	if (i != 0)
		write(1, "sa\n", 3);
}

void	ft_sb(t_list **list_b, int i)
{
	t_list	*node_to_move;
	t_list	*new_start;

	node_to_move = *list_b;
	if (*list_b == NULL || node_to_move->next == NULL)
		return ;
	*list_b = node_to_move->next;
	new_start = *list_b;
	node_to_move->next = new_start->next;
	new_start->next = node_to_move;
	if (i != 0)
		write(1, "sb\n", 3);
}

void	ft_ss(t_list **list_a, t_list **list_b)
{
	ft_sa(list_a, 0);
	ft_sb(list_b, 0);
	write(1, "ss\n", 3);
}

void	ft_pa(t_list **list_a, t_list **list_b)
{
	t_list	*node_to_move;

	if (*list_b == NULL)
		return ;
	node_to_move = *list_b;
	*list_b = node_to_move->next;
	node_to_move->next = *list_a;
	*list_a = node_to_move;
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **list_a, t_list **list_b)
{
	t_list	*node_to_move;

	if (*list_a == NULL)
		return ;
	node_to_move = *list_a;
	*list_a = node_to_move->next;
	node_to_move->next = *list_b;
	*list_b = node_to_move;
	write(1, "pb\n", 3);
}
