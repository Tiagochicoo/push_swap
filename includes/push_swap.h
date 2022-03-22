/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:49:43 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/22 08:10:22 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}			t_stack;

typedef struct s_stop
{
	int	stop;
	int	stop1;
	int	stop2;
	int	stop3;
	int	count;
	int	count1;
}			t_stop;

t_stack	*ft_stacknew(int content);
void	ft_stackadd_back(t_stack**lst, t_stack*new);
void	ft_stackadd_front(t_stack**lst, t_stack*new);
void	free_stack(t_stack **stack);
void	ft_stacksort(t_stack*head);
t_stack	*ft_stackdup(t_stack*head);
t_stack	*ft_stacklast(t_stack*lst);
int		ft_stacksize(t_stack*lst);
void	low_median_push_a(t_stack**b, t_stack**a);
void	low_median_push_b(t_stack**a, t_stack**b, int stop);
void	top_median_push_a(t_stack**b, t_stack**a);
void	top_median_push_b(t_stack**a, t_stack**b, int stop);
void	quarter_push_a(t_stack**src, t_stack**dest);
void	quarter_push_b(t_stack**src, t_stack**dest);
void	order_in_b(t_stack**a, t_stack**b);
void	order_in_b2(t_stack**a, t_stack**b);
int		check_args(char**argv);
int		check_arg(char**argv);
void	convert_to_int(t_stack*a);
t_stack	*init_a(int argc, char**argv, t_stack*a);
int		check_order(t_stack *a);
t_stack	*sort_2_args(t_stack*head);
t_stack	*sort_3_args(t_stack**a);
void	sort_3_args_b(t_stack**b);
t_stack	*sort_4_args(t_stack**a, t_stack**b);
void	print_args(t_stack*head);
void	sa(t_stack**a);
void	sb(t_stack**b);
void	ra(t_stack**a);
void	rb(t_stack**b);
void	rra(t_stack**a);
void	rrb(t_stack**b);
void	rr(t_stack**a, t_stack**b);
void	pa(t_stack**a, t_stack**b);
void	pb(t_stack**b, t_stack**a);
t_stack	*sort_5_or_less(t_stack*a, t_stack*b);
t_stack	*sort_6_args(t_stack**a, t_stack**b);
int		ft_biggest(t_stack**head);
int		ft_smallest(t_stack**head);
int		ft_stack_median(t_stack**head);
int		is_ordered_loop(t_stack**head);
void	sort_lower(t_stack**a, t_stack**b, t_stop*stop, int i);
void	sort_top(t_stack**a, t_stack**b, t_stop*stop, int i);
int		up_down(t_stack*b, int min);
void	init_stop(t_stop*stop);
t_stop	*stop_func(t_stop*stop);
t_stop	*stop_func2(int count, t_stop*stop);
t_stop	*stop_func3(int count, t_stop*stop, int content);
t_stop	*stop_func4(int count, t_stop*stop, int content);

#endif