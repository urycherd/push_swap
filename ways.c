/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:36:09 by urycherd          #+#    #+#             */
/*   Updated: 2022/02/15 13:56:28 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_way_1(t_list **list_a, t_list **list_b, t_list *b)
{
	int	i;

	i = b->rb;
	while (i-- > 0)
		ft_rb(list_b, 1);
	i = b->rra;
	while (i-- > 0)
		ft_rra(list_a, 1);
}

void	ft_way_2(t_list **list_a, t_list **list_b, t_list *b)
{
	int	i;

	i = b->ra;
	while (i-- > 0)
		ft_ra(list_a, 1);
	i = b->rrb;
	while (i-- > 0)
		ft_rrb(list_b, 1);
}

void	ft_way_3(t_list **list_a, t_list **list_b, t_list *b)
{
	int	i;

	i = b->rr;
	while (i-- > 0)
		ft_rr(list_a, list_b);
	i = b->ra - b->rb;
	while (i-- > 0)
		ft_ra(list_a, 1);
}

void	ft_way_4(t_list **list_a, t_list **list_b, t_list *b)
{
	int	i;

	i = b->rr;
	while (i-- > 0)
		ft_rr(list_a, list_b);
	i = b->rb - b->ra;
	while (i-- > 0)
		ft_rb(list_b, 1);
}

void	ft_way_5(t_list **list_a, t_list **list_b, t_list *b)
{
	int	i;

	i = b->rrr;
	while (i-- > 0)
		ft_rrr(list_a, list_b);
	i = b->rra - b->rrb;
	while (i-- > 0)
		ft_rra(list_a, 1);
}
