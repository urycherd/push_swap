/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:02:40 by urycherd          #+#    #+#             */
/*   Updated: 2022/02/15 18:31:46 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_vals	*ft_full_mmm(int *nums, int hmn)
{
	t_vals	*value;

	value = (t_vals *)malloc(sizeof(value));
	value->min = nums[0];
	value->med = nums[hmn / 2];
	value->max = nums[hmn - 1];
	return (value);
}

int	ft_sorted_list(t_list **list, int num_amount)
{
	t_list	*val;
	int		i;

	val = *list;
	i = ft_lstsize(*list);
	if (i != num_amount)
		return (0);
	while (val->content < val->next->content)
	{
		val = val->next;
		if (val->next == NULL)
			return (1);
	}
	return (0);
}

void	ft_put_to_b(t_list **list_a, t_list **list_b, t_vals *vals_mmm)
{
	t_list	*pointer;
	t_vals	*mmm;

	mmm = vals_mmm;
	pointer = *list_a;
	while (ft_lstsize(*list_a) > 3)
	{
		if (ft_lstsize(*list_a) == 3)
			break ;
		if (ft_nums_compare(pointer->content, vals_mmm) != 1)
		{
			ft_pb(list_a, list_b);
			pointer = *list_a;
		}
		else
		{
			ft_ra(list_a, 1);
			pointer = *list_a;
		}
	}
}

void	ft_do_smth(t_list **list_a, t_vals *vals_mmm)
{
	t_list	*list_b;

	list_b = NULL;
	if (vals_mmm->argc > 3)
		ft_put_to_b(list_a, &list_b, vals_mmm);
	ft_sort_mmm(list_a, vals_mmm);
	special_mom(&list_b, (vals_mmm->argc - 1));
	ft_fun(list_a, &list_b);
	final_sort_a(list_a, vals_mmm);
	free (list_b);
}

void	ft_please_sort_them(t_list	**list_a, int *nums, int argc)
{
	int		hmn;
	t_vals	*vals_mmm;

	hmn = argc - 1;
	nums = ft_buble_sort(nums, hmn);
	vals_mmm = ft_full_mmm(nums, hmn);
	vals_mmm->argc = argc;
	if (!ft_sorted_list(list_a, hmn))
		ft_do_smth(list_a, vals_mmm);
	free(vals_mmm);
}
