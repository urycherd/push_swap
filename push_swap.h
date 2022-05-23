/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:57:27 by urycherd          #+#    #+#             */
/*   Updated: 2022/02/15 18:29:51 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_vals
{
	int	min;
	int	max;
	int	med;
	int	argc;
}		t_vals;

typedef struct s_list
{
	int				content;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				len;
	int				way;
	struct s_list	*next;
}		t_list;

t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_please_sort_them(t_list	**list_a, int *nums, int argc);
void		ft_sort_mmm(t_list **list_a, t_vals *vals_mmm);
int			*ft_buble_sort(int *nums, int hmn);
int			*make_nums(int argc, char **argv);
int			ft_atoi(const char *str);
long long	*make_long_nums(int argc, char **argv);
long long	ft_long_atoi(const char *str);
int			ft_sorted_list(t_list **list, int num_amount);
int			ft_isdigit(int c);
int			ft_nums_compare(int a, t_vals *vals_mmm);
int			oversize_check(int argc, char **argv);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
void		final_sort_a(t_list	**list_a, t_vals *vals_mmm);
void		count_way_num(t_list **list_a, t_list **list_b, t_list	*b);
void		ft_way_1(t_list **list_a, t_list **list_b, t_list *b);
void		ft_way_2(t_list **list_a, t_list **list_b, t_list *b);
void		ft_way_3(t_list **list_a, t_list **list_b, t_list *b);
void		ft_way_4(t_list **list_a, t_list **list_b, t_list *b);
void		ft_way_5(t_list **list_a, t_list **list_b, t_list *b);
void		ft_way_6(t_list **list_a, t_list **list_b, t_list *b);
void		ft_fun(t_list **list_a, t_list **list_b);
void		free_after_split(char **argv);
void		free_stack(t_list **head);
void		ft_error(void);
void		special_mom(t_list **list_b, int num);

void		ft_sa(t_list **list_a, int i);
void		ft_sb(t_list **list_b, int i);
void		ft_ss(t_list **list_a, t_list **list_b);
void		ft_pa(t_list **list_a, t_list **list_b);
void		ft_pb(t_list **list_a, t_list **list_b);
void		ft_ra(t_list **list_a, int i);
void		ft_rb(t_list **list_b, int i);
void		ft_rr(t_list **list_a, t_list **list_b);
void		ft_rra(t_list **list_a, int i);
void		ft_rrb(t_list **list_b, int i);
void		ft_rrr(t_list **list_a, t_list **list_b);
#endif