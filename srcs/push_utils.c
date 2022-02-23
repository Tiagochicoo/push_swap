/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/23 18:40:06 by tpereira         ###   ########.fr       */
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

void	low_median_push_a(t_stack**b, t_stack**a)
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
		if ((*b)->content < med)
		{
			mid--;
			pa(a, b);
		}
		else
			rb(b);
	}
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
		if ((*b)->content > med && mid--)
		{
			while ((*b)->content < (*b)->next->content)
				sb(b);
			pa(a, b);
		}
		else if ((*b) == ft_smallest(b))
		{
			pa(a, b);
			ra(a);
		}
		else
			rb(b);
	}
}

void	low_median_push_b(t_stack**a, t_stack**b, int min)
{
	int	mid;
	int	med;

	mid = ft_stacksize(*a) / 2;
	med = ft_stack_median(a);
	while (mid && (*a)->content > min)
	{
		if ((*a)->content < med && mid--)
			pb(b, a);
		else
			ra(a);
	}
}

void	top_median_push_b(t_stack**a, t_stack**b, int max)
{
	int	mid;
	int	med;

	mid = ft_stacksize(*a) / 2;
	med = ft_stack_median(a);
	while (mid && (*a)->content < max)
	{
		if ((*a)->content < med && mid--)
			pb(b, a);
		else
			ra(a);
	}
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
