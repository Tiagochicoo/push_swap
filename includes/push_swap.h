/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:49:43 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/31 18:29:37 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_props
{
	int mid_index;
	int	arg_count;
	int args[];
}			t_props;

typedef	struct s_stack
{
	int				content;
	struct s_stack	*next;
}			t_stack;

t_stack	*ft_stacknew(int content);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
int	ft_stacksize(t_stack *lst);

int		check_args(int argc, char**argv);
int		check_arg(char**argv);
void	convert_to_int(t_stack *a);
t_stack	*init_a(int argc, char**argv);
int		check_order(t_stack*a);
int		stack_size(t_stack*head);
void	sort_2_args(t_stack*a);
void	sort_3_args(t_stack**a);
void	print_args(t_stack *head);
t_stack	*pop_head(t_stack**head);
void	sa(t_stack**a);
void	ra(t_stack*a);
void	rra(t_stack**a);
void	pa(t_stack**a, t_stack**b);
void	pb(t_stack**b, t_stack**a);
t_props	*fill_props(t_stack*a, int argc);
void	sort_less_than_5(t_stack*a, t_stack*b);

#endif