/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:52:37 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/14 18:54:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack*a, t_stack*b)
{
	(void)b;
	if (a->size > 1)
	{
		ft_putendl_fd("ra", 1);
		rotate(a);
	}
}

void	rra(t_stack*a, t_stack*b)
{
	(void)b;
	if (a->size > 1)
	{
		ft_putendl_fd("rra", 1);
		rev_rotate(a);
	}
}

void	sa(t_stack*a, t_stack*b)
{
	(void)b;
	if (a->size >1)
	{
		ft_putendl_fd("sa", 1);
		swap(a);
	}
}
