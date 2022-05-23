/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_funct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:53:23 by urycherd          #+#    #+#             */
/*   Updated: 2022/02/15 12:49:33 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_mmm(t_list **list_a, t_vals *vals)
{
	t_list	*point;

	point = *list_a;
	if (point->content == vals->max && point->next->content == vals->med)
		ft_sa(list_a, 1);
	else if (point->content == vals->med && point->next->content == vals->min)
		ft_sa(list_a, 1);
	else if (point->content == vals->min && point->next->content == vals->max)
		ft_sa(list_a, 1);
}

int	pos_from_top(t_list *list, int value)
{
	int	index;

	index = 0;
	while (list->content != value)
	{
		list = list->next;
		index++;
	}
	return (index);
}

int	*make_nums(int argc, char **argv)
{
	int	*nums;
	int	i;
	int	j;

	i = 0;
	j = 1;
	nums = (int *)malloc(sizeof(int) * (argc - 1));
	while (i < argc - 1)
		nums[i++] = ft_atoi(argv[j++]);
	return (nums);
}

void	put_from_b_to_a(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;
	t_list	*last;

	while (*list_b != NULL)
	{
		a = *list_a;
		b = *list_b;
		last = ft_lstlast(a);
		if (a->content > b->content && last->content < b->content)
			ft_pa(list_a, list_b);
		else
		{
			if (pos_from_top(*list_a, a->content) > ft_lstsize(*list_a) / 2)
				ft_ra(list_a, 1);
			else
				ft_rra(list_a, 1);
		}
	}
}

void	final_sort_a(t_list	**list_a, t_vals *vals_mmm)
{
	t_list	*a;
	int		min_position;

	a = *list_a;
	while (a->content != vals_mmm->min)
	{
		min_position = pos_from_top(*list_a, vals_mmm->min);
		if (min_position < vals_mmm->argc / 2)
		{
			ft_ra(list_a, 1);
			a = *list_a;
		}
		else
		{
			ft_rra(list_a, 1);
			a = *list_a;
		}
	}
}
