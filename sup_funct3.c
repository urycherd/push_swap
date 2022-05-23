/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_funct3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:00:35 by urycherd          #+#    #+#             */
/*   Updated: 2022/02/15 17:39:23 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	score_ra(t_list *lst, int num)
{
	int		lngt;
	t_list	*last;

	last = ft_lstlast(lst);
	if (lst->content > num && last->content < num)
		return (0);
	lngt = 1;
	while (!(lst->content < num && lst->next->content > num))
	{
		lst = lst->next;
		lngt++;
	}
	return (lngt);
}

static int	score_rb(t_list *lst, int num)
{
	int	lngt;

	lngt = 0;
	while (lst->content != num)
	{
		lst = lst->next;
		lngt++;
	}
	return (lngt);
}

static void	way_5_6(t_list *b)
{
	if (b->rr + b->ra - b->rb == b->rrr + b->rra - b->rr)
	{
		if (b->rr + b->ra - b->rb == b->len)
		{
			if (b->ra < b->rra)
				b->way = 3;
		}
	}
	if (b->rb - b->ra >= 0 && b->rr + b->rb - b->ra < b->len)
	{
		b->len = b->rr + b->rb - b->ra;
		b->way = 4;
	}
	if (b->rrb - b->rra >= 0 && b->rrr + b->rrb - b->rra < b->len)
	{
		b->len = b->rrr + b->rrb - b->rra;
		b->way = 6;
	}
}

static void	make_len(t_list *b)
{
	b->len = b->rb + b->rra;
	b->way = 1;
	if (b->rrb + b->ra < b->len)
	{
		b->len = b->rrb + b->ra;
		b->way = 2;
	}
	if (b->rrb + b->ra == b->rb + b->rra)
	{
		if (b->ra > b->rra)
			b->way = 1;
	}
	if (b->ra - b->rb > 0 && b->rr + b->ra - b->rb < b->len)
	{
		b->len = b->rr + b->ra - b->rb;
		b->way = 3;
	}
	if (b->rra - b->rrb > 0 && b->rrr + b->rra - b->rrb < b->len)
	{
		b->len = b->rrr + b->rra - b->rrb;
		b->way = 5;
	}
	way_5_6 (b);
}

void	count_way_num(t_list **list_a, t_list **list_b, t_list	*b)
{
	b->ra = score_ra(*list_a, b->content);
	b->rra = ft_lstsize(*list_a) - b->ra;
	b->rb = score_rb(*list_b, b->content);
	b->rrb = ft_lstsize(*list_b) - b->rb;
	b->rr = b->rb;
	b->rrr = b->rrb;
	if (b->ra < b->rb)
		b->rr = b->ra;
	if (b->rra < b->rrb)
		b->rrr = b->rra;
	make_len(b);
}
