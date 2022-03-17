/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:05:11 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/17 17:28:55 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	order_in_b(t_stack**a, t_stack**b)
{
	int	min;
	int	size;
	int	rotate;

	min = 0;
	while (*b)
	{
		min = ft_smallest(b);
		rotate = up_down(*b, min);
		if (ft_stacksize(*b) == 1)
			pa(a, b);
		if ((*a)->content == ft_biggest(a))
			ra(a);
		while ((*b) && (*b)->content > min)
		{
			if (rotate == 1)
				rb(b);
			else
				rrb(b);
		}
		if (ft_stacksize(*b) > 1)
		{
			pa(a, b);
			ra(a);
		}
	}
}

void	sort_3_args_b(t_stack**b)
{
	int		first;
	int		second;
	int		third;

	while (!check_order(*b))
	{
		first = (*b)->content;
		second = (*b)->next->content;
		third = (*b)->next->next->content;
		if (first > second && first > third && second < third)
			rb(b);
		else if (first < second && second > third)
			rra(b);
		else if (first > second && second < third)
			sb(b);
		else if (first > second && second > third)
			sb(b);
	}
}

void	sort_6_args(t_stack**a, t_stack**b)
{
	low_median_push_b(a, b, INT_MAX);
	sort_3_args(a);
	while (*b)
	{
		if ((*b)->content == ft_biggest(b))
			pa(a, b);
		else
			rb(b);
	}
}

int	sort_lower(t_stack**a, t_stack**b, int stop)
{
	int	i;

	i = 20;
	if (ft_stacksize(*a) > 100)
		i = 45;
	if (!*b && !check_order(*a))
	{
		low_median_push_b(a, b, stop);
		stop = (*a)->content;
	}
	if (ft_stacksize(*b) > i)
		top_median_push_a(b, a);
	else
		order_in_b(a, b);
	return (stop);
}

int	sort_top(t_stack**a, t_stack**b, int stop2)
{
	int	i;

	i = 20;
	if (ft_stacksize(*a) > 100)
		i = 45;
	if (!*b && !check_order(*a))
	{
		top_median_push_b(a, b, stop2);
		stop2 = (*a)->content;
	}
	if (ft_stacksize(*b) > i)
		top_median_push_a(b, a);
	else
		order_in_b(a, b);
	return (stop2);
}
