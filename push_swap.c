/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:55:03 by urycherd          #+#    #+#             */
/*   Updated: 2022/02/15 18:30:27 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	split_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

static int	ft_compare(int *nums, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 1;
		while (i + j < argc - 1)
		{
			if (nums[i] == nums[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_checker_not_valid(int argc, char **argv, int **nums)
{
	int			i;
	int			j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j++]) != 1)
				return (1);
		}
	}
	if (oversize_check(argc, argv))
		return (1);
	*nums = (int *)make_nums(argc, argv);
	if (ft_compare(*nums, argc) == 1)
		return (1);
	return (0);
}

static t_list	*create_list(int *nums, int argc)
{
	t_list	*vals;
	t_list	*new_node_adress;
	int		i;

	i = 0;
	vals = ft_lstnew(nums[i++]);
	while (i < (argc - 1))
	{
		new_node_adress = ft_lstnew(nums[i++]);
		ft_lstadd_back(&vals, new_node_adress);
	}
	return (vals);
}

int	main(int argc, char **argv)
{	
	t_list	*list_a;
	int		*nums;
	char	*str;

	if (argc == 2)
	{
		str = ft_strjoin("?push_swap ", argv[1]);
		argv = ft_split(str, ' ');
		free(str);
		argc = split_size(argv);
	}
	if (ft_checker_not_valid(argc, argv, &nums))
		ft_error();
	if (argc > 2)
	{
		list_a = create_list(nums, argc);
		ft_please_sort_them(&list_a, nums, argc);
		free(nums);
		free_stack(&list_a);
	}
	if (argv[0][0] == '?')
		free_after_split(argv);
	return (0);
}
