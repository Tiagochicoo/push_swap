/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_or_less.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/03 20:05:28 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2_args(t_stack*head)
{
	int	one;
	int	two;

	one = head->content;
	two = head->next->content;
	if (one > two)
		sa(&head);
}

void	sort_5_args(t_stack**a, t_stack**b)
{
	int	moves;

	moves = is_ordered_loop(a);
	if (moves == 1)
	{
		while (!check_order(*a))
			ra(a);
	}
	else
	{
		pb(b, a);
		pb(b, a);
		if ((*b) != NULL && check_order(*b))
			sb(b);
		sort_3_args(a);
		while ((*b) != NULL)
		{
			while ((*b)->content > (*a)->content && moves++ < (ft_stacksize(*a) - 1))
				ra(a);
			pa(a, b);
			while (!(check_order(*a)) && is_ordered_loop(a))
				rra(a);
		}
	}
}

void	sort_5_or_less(t_stack*a, t_stack*b)
{
	int	size;

	size = ft_stacksize(a);
	if (size == 2)
		sort_2_args(a);
	else if (size == 3)
		sort_3_args(&a);
	else if (size == 4)
		sort_4_args(&a, &b);
	else if (size == 5)
		sort_5_args(&a, &b);
}
