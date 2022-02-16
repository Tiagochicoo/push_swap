/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:49:43 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/16 19:55:23 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef	struct s_stack
{
	t_list	*head;
	int		size;
}	t_stack;

int	check_args(int argc, char**argv);
t_list	*init_a(int argc, char**argv);

int		check_order(t_list*stack);
void	small_sort(t_stack*a, t_stack*b);
void	medium_sort(t_stack*a, t_stack*b);

void	pa(t_stack*a, t_stack*b);
void	ra(t_stack*a, t_stack*b);
void	sa(t_stack*a, t_stack*b);
void	rra(t_stack*a, t_stack*b);
void	pb(t_stack*a, t_stack*b);
void	rb(t_stack*a, t_stack*b);
void	sb(t_stack*a, t_stack*b);
void	rrb(t_stack*a, t_stack*b);
void	swap(t_stack*stack);
void	push(t_stack*stack, void*content);
void	*pop(t_stack*stack);
int		median(t_stack*stack);
void	*find_med(t_list*list);

void	*find_max(t_list*list);
void	*find_min(t_list*list);

void	shift(t_stack*stack, void*content);
void	*unshift(t_stack*stack);
void	rotate(t_stack*stack);
void	rev_rotate(t_stack*stack);

#endif