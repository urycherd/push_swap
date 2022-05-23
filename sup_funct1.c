/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_funct1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:17:01 by urycherd          #+#    #+#             */
/*   Updated: 2022/02/08 17:30:18 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_long_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	summ;

	summ = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		summ = summ * 10 + (str[i] - '0');
		i++;
	}
	return (summ * sign);
}

long long	*make_long_nums(int argc, char **argv)
{
	long long	*nums;
	int			i;
	int			j;

	i = 0;
	j = 1;
	nums = (long long *)malloc(sizeof(long long) * (argc - 1));
	while (i < argc - 1)
		nums[i++] = ft_long_atoi(argv[j++]);
	return (nums);
}

int	oversize_check(int argc, char **argv)
{
	long long	*checker;
	int			i;

	checker = make_long_nums(argc, argv);
	i = 0;
	while (i < argc - 1)
	{
		if (checker[i] > 2147483647 || checker[i++] < -2147483647)
			return (1);
	}
	free(checker);
	return (0);
}

int	ft_nums_compare(int a, t_vals *vals_mmm)
{
	t_vals	*val;

	val = vals_mmm;
	if (val->max == a || val->med == a || val->min == a)
		return (1);
	return (0);
}

int	*ft_buble_sort(int *nums, int hmn)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < hmn - 1)
	{
		j = 0;
		while (j < hmn - i - 1)
		{
			if (nums[j] > nums[j + 1])
			{
				tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (nums);
}
