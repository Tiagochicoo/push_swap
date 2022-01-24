/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:49:43 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/24 19:57:21 by tpereira         ###   ########.fr       */
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
	void			*content;
	struct s_stack	*next;
}				t_stack;

typedef struct s_props
{
	int mid_index;
	int	arg_count;
	int args[];
}			t_props;


int		check_args(int argc, char**argv);
int		check_arg(char**argv);
void	convert_to_int(t_stack *a);
t_stack	*init_a(int argc, char**argv);
int		check_order(t_stack *a);
int		stack_size(t_stack *head);
void	sort_2_args(t_stack *a);
void	sort_3_args(t_stack *a);
void	print_args(t_stack *head);
t_stack	*pop_head(t_stack**head);
void	sa(t_stack *a);
void	ra(t_stack *a);
void	pa(t_stack**a, t_stack**b);
void	pb(t_stack**b, t_stack**a);
t_props	*fill_props(t_stack*a, int argc);

#endif