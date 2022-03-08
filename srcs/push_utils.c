/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/08 19:52:44 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_to_push(t_stack*head, int median, int min)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		count;

	count = 0;
	temp = ft_stackdup(head);
	ft_stacksort(temp);
	temp2 = temp;
	while (temp->next && temp->content > min)
		temp = temp->next;
	while (temp->next && temp->content < median)
	{
		count++;
		temp = temp->next;
	}
	free_stack(&temp2);
	return (count);
}

void	top_median_push_a(t_stack**b, t_stack**a)
{
	int	mid;
	int	med;
	int	flag;

	flag = 0;
	mid = ft_stacksize(*b) / 2;
	med = ft_stack_median(b);
	while (mid)
	{
		if (mid == 1)
			flag++;
		if (flag == 2)
			return ;
		if ((*b)->content >= med && mid--)
		{
			while ((*b)->content < (*b)->next->content)
				rb(b);
			pa(a, b);
		}
		else
			rb(b);
	}
}

int	low_median_push_b(t_stack**a, t_stack**b)
{
	int	min;
	int	mid;
	int	med;
	int	ra_count;

	ra_count = 0;
	min = ft_smallest(a)->content;
	mid = ft_stacksize(*a) / 2;
	med = ft_stack_median(a);
	while (mid > 0)
	{
		if ((*a)->content < med && mid--)
			pb(b, a);
		else if ((*a)->content > min)
		{
			ra(a);
			ra_count++;
		}
	}
	return (ra_count);
}

void	top_median_push_b(t_stack**a, t_stack**b)
{
	int	mid;
	int	med;

	mid = ft_stacksize(*a) / 2;
	med = ft_stack_median(a);
	while (mid)
	{
		if ((*a)->content < med && mid--)
			pb(b, a);
		else
			ra(a);
	}
}
