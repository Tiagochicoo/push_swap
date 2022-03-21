/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:05:11 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/21 18:34:00 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	order_in_b(t_stack**a, t_stack**b)
{
	int	min;

	min = 0;
	while (*b)
	{
		min = ft_smallest(b);
		if (ft_stacksize(*b) == 1)
			pa(a, b);
		if ((*a)->content == ft_biggest(a))
			ra(a);
		while ((*b) && (*b)->content > min)
			rb(b);
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

t_stack	*sort_6_args(t_stack**a, t_stack**b)
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
	return (*a);
}

void	sort_lower(t_stack**a, t_stack**b, t_stop*stop, int i)
{
	static int	count = 0;
	static int	stop1 = INT_MAX;
	static int	stop2 = INT_MAX;
	static int	stop3 = INT_MAX;

	i = 19;
	if (ft_stacksize(*a) > 120)
		i = 42;
	if (!*b && !check_order(*a))
	{
		stop = stop_func(stop);
		low_median_push_b(a, b, (stop)->stop);
		if ((*a)->content == ft_biggest(a))
			ra(a);
		stop->stop = (*a)->content;
		stop = stop_func2(count, stop);
	}
	if (ft_stacksize(*b) > i)
	{
		if (count == 0)
			stop1 = (*a)->content;
		else if (count == 1)
			stop2 = (*a)->content;
		else if (count == 2)
			stop3 = (*a)->content;
		else if (count >= 3)
			stop2 = (*a)->content;
		top_median_push_a(b, a);
		count++;
	}
	else
		order_in_b(a, b);
}

int	sort_top(t_stack**a, t_stack**b, int stop, int i)
{
	static int	count = 0;
	static int	count1 = 0;
	static int	stop1 = INT_MAX;
	static int	stop2 = INT_MAX;
	static int	stop3 = INT_MAX;

	i = 20;
	if (ft_stacksize(*a) > 120)
		i = 50;
	if (!*b && !check_order(*a))
	{
		if (stop3 != INT_MAX && count1++ == 0)
			stop = stop3;
		else if (stop2 != INT_MAX && count1++ < 12)
			stop = stop2;
		else if (stop1 != INT_MAX && count1++ < 20)
			stop = stop1;
		top_median_push_b(a, b, stop);
		stop = (*a)->content;
	}
	if (ft_stacksize(*b) > i)
	{
		if (count == 0)
			stop1 = (*a)->content;
		else if (count == 1)
			stop2 = (*a)->content;
		else if (count == 2)
			stop3 = (*a)->content;
		else if (count < 5)
			stop2 = (*a)->content;
		else if (count < 15)
			stop1 = (*a)->content;
		top_median_push_a(b, a);
		count++;
	}
	else
		order_in_b(a, b);
	return (stop2);
}
