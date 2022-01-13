/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:49:43 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/13 22:31:50 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

int		check_args(int argc, char**argv);
int		check_arg(char**argv);
void	convert_to_int(t_list *a);
t_list	*init_a(int argc, char**argv);
int		check_order(t_list *a);
int		stack_size(t_list *head);
void	sort_2_args(t_list *a);
void	sort_3_args(t_list *a);
void	print_args(t_list *head);
void	pop_head(t_list**head);
void	sa(t_list *a);
void	ra(t_list *a);
void	pa(t_list**a, t_list**b);

#endif