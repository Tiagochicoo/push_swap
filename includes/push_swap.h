/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:49:43 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/07 19:25:28 by tpereira         ###   ########.fr       */
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

t_stack	*ft_stacknew(int content);
void	ft_stackadd_back(t_stack**lst, t_stack*new);
void	ft_stackadd_front(t_stack**lst, t_stack*new);
void	free_stack(t_stack **stack);
void	ft_stacksort(t_stack*head);
t_stack	*ft_stackdup(t_stack*head);
t_stack	*ft_stacklast(t_stack*lst);
int		ft_stacksize(t_stack*lst);
int		ft_count_to_push(t_stack*head, int median, int min);
t_stack	*ft_to_order(t_stack*a);
void	low_median_push_a(t_stack**b, t_stack**a);
void	low_median_push_b(t_stack**a, t_stack**b);
void	top_median_push_a(t_stack**b, t_stack**a);
void	top_median_push_b(t_stack**a, t_stack**b);
void	quarter_push_a(t_stack**src, t_stack**dest);
void	quarter_push_b(t_stack**src, t_stack**dest);
void	order_in_b(t_stack**a, t_stack**b);
int		check_args(int argc, char**argv);
int		check_arg(char**argv);
void	convert_to_int(t_stack*a);
t_stack	*init_a(int argc, char**argv, t_stack*a);
int		check_order(t_stack *a);
void	sort_2_args(t_stack*head);
void	sort_3_args(t_stack**a);
void	sort_3_args_b(t_stack**b);
void	sort_4_args(t_stack**a, t_stack**b);
void	print_args(t_stack*head);
void	sa(t_stack**a);
void	sb(t_stack**b);
void	ra(t_stack**a);
void	rb(t_stack**b);
void	rra(t_stack**a);
void	pa(t_stack**a, t_stack**b);
void	pb(t_stack**b, t_stack**a);
void	sort_5_or_less(t_stack*a, t_stack*b);
t_stack	*ft_biggest(t_stack**head);
t_stack	*ft_smallest(t_stack**head);
int		ft_stack_median(t_stack**head);
int		is_ordered_loop(t_stack**head);

#endif