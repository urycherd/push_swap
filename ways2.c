/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:36:09 by urycherd          #+#    #+#             */
/*   Updated: 2022/02/15 18:32:09 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_way_6(t_list **list_a, t_list **list_b, t_list *b)
{
	int	i;

	i = b->rrr;
	while (i-- > 0)
		ft_rrr(list_a, list_b);
	i = b->rrb - b->rra;
	while (i-- > 0)
		ft_rrb(list_b, 1);
}

void	special_mom(t_list **list_b, int num)
{
	t_list	*val;

	val = *list_b;
	if (val->content < val->next->content && num == 5)
		ft_sb(list_b, 1);
}

void	free_after_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
}

void	free_stack(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit (0);
}
