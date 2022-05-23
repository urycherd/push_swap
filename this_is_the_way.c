/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_is_the_way.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:00:35 by urycherd          #+#    #+#             */
/*   Updated: 2022/02/15 18:20:57 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_win(t_list	*b)
{	
	int		min_route;
	t_list	*win;

	min_route = b->len;
	win = b;
	while (b != NULL)
	{
		if (min_route > b->len)
		{
			min_route = b->len;
			win = b;
		}
		b = b->next;
	}
	return (win);
}

void	move_b(t_list **list_a, t_list **list_b, t_list *b)
{
	if (b->way == 1)
		ft_way_1(list_a, list_b, b);
	if (b->way == 2)
		ft_way_2(list_a, list_b, b);
	if (b->way == 3)
		ft_way_3(list_a, list_b, b);
	if (b->way == 4)
		ft_way_4(list_a, list_b, b);
	if (b->way == 5)
		ft_way_5(list_a, list_b, b);
	if (b->way == 6)
		ft_way_6(list_a, list_b, b);
	ft_pa(list_a, list_b);
}

void	ft_fun(t_list **list_a, t_list **list_b)
{
	t_list	*b;

	while (*list_b != NULL)
	{
		b = *list_b;
		while (b != NULL)
		{
			count_way_num(list_a, list_b, b);
			b = b->next;
		}
		b = *list_b;
		b = ft_win (b);
		move_b(list_a, list_b, b);
	}
}
