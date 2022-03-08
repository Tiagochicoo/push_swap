/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/08 19:37:05 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_quarter(t_stack**head)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		med;
	int		mid;

	med = 0;
	mid = ft_stacksize(*head) / 4;
	temp = ft_stackdup(*head);
	temp2 = temp;
	ft_stacksort(temp);
	while (mid--)
		temp = temp->next;
	med = temp->content;
	free_stack(&temp2);
	return (med);
}

int	top_median_push_a(t_stack**b, t_stack**a, int min)
{
	int	mid;
	int	med;
	int	flag;
	int	smallest;

	flag = 0;
	smallest = 0;
	mid = ft_stacksize(*b) / 2;
	med = ft_stack_median(b, ft_smallest(b)->content, ft_biggest(b)->content);
	while (mid)
	{
		if (mid == 1 || mid == 2)
			flag++;
		if (flag == 2)
			return (smallest);
		// if (ft_stacksize(*b) == 1 && (*b)->content >= min)
		// 	pa(a, b);
		else if ((*b) == ft_smallest(b) && mid--)
		{
			pa(a, b);
			smallest = (*a)->content;
			ra(a);
		}
		else if ((*b)->content > med && mid--)
		{
			while ((*b)->content < (*b)->next->content)
				rb(b);
			pa(a, b);
		}
		else
			rb(b);
	}
	return (smallest);
}

int	low_median_push_b(t_stack**a, t_stack**b)
{
	int	mid;
	int	min;
	int	max;
	int	med;
	int	ra_count;
	static int	iter = 1;

	ra_count = 0;
	min = ft_smallest(a)->content;
	max = ft_biggest(a)->content;
	mid = (ft_stacksize(*a) * (iter % 2)) / 2;
	med = ft_stack_median(a, min, max);
	if (min == INT_MIN)
		min = INT_MAX;
	while (mid > 0)
	{
		// if ((*a)->content == min)
		// 	return (ra_count);
		if ((*a)->content < med && mid--)
			pb(b, a);
		else
		{
			ra(a);
			ra_count++;
		}
	}
	iter++;
	return (ra_count);
}

void	quarter_push_a(t_stack**b, t_stack**a)
{
	int	qrt;
	int	med;

	qrt = ft_stacksize(*b) / 4;
	med = ft_stack_quarter(b);
	while (qrt)
	{
		if ((*b)->content < med)
		{
			qrt--;
			pa(a, b);
		}
		else
			rb(b);
	}
}

void	quarter_push_b(t_stack**a, t_stack**b)
{
	int	qrt;
	int	med;

	qrt = ft_stacksize(*a) / 4;
	med = ft_stack_quarter(a);
	while (qrt)
	{
		if ((*a)->content < med)
		{
			qrt--;
			pb(b, a);
		}
		else
			ra(a);
	}
}
