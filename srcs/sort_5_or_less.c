/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_or_less.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/17 17:50:08 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*sort_2_args(t_stack*head)
{
	int	one;
	int	two;

	one = head->content;
	two = head->next->content;
	if (one > two)
		sa(&head);
	return (head);
}

t_stack	*sort_3_args(t_stack**a)
{
	int		first;
	int		second;
	int		third;

	while (!check_order(*a))
	{
		first = (*a)->content;
		second = (*a)->next->content;
		third = (*a)->next->next->content;
		if (first > second && first > third && second < third)
			ra(a);
		else if (first < second && second > third)
			rra(a);
		else if (first > second && second < third)
			sa(a);
		else if (first > second && second > third)
			sa(a);
	}
	return (*a);
}

t_stack	*sort_4_args(t_stack**a, t_stack**b)
{
	int	i;
	int	j;
	int	num;
	int	size;

	i = 0;
	j = 0;
	while (!check_order(*a))
	{
		pb(b, a);
		sort_3_args(a);
		num = (*a)->content;
		while ((*b) != NULL)
		{
			size = ft_stacksize(*a);
			while ((*a)->content < (*b)->content && i++ < size)
			{
				ra(a);
				j++;
			}
			pa(a, b);
		}
		while (j-- > 0)
			rra(a);
	}
	return (*a);
}

t_stack	*sort_5_args(t_stack**a, t_stack**b)
{
	low_median_push_b(a, b, INT_MAX);
	sort_3_args(a);
	if (check_order(*b))
		sb(b);
	while ((*b))
		pa(a, b);
	return (*a);
}

t_stack	*sort_5_or_less(t_stack*a, t_stack*b)
{
	int	size;

	size = ft_stacksize(a);
	if (size == 2)
		a = sort_2_args(a);
	else if (size == 3)
		a = sort_3_args(&a);
	else if (size == 4)
		a = sort_4_args(&a, &b);
	else if (size == 5)
		a = sort_5_args(&a, &b);
	else if (size == 6)
		a = sort_6_args(&a, &b);
	return (a);
}
