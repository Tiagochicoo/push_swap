/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_or_less.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/23 20:50:06 by tpereira         ###   ########.fr       */
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

void	sort_3_args(t_stack**a)
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

void	sort_4_args(t_stack**a, t_stack**b)
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
}

void	sort_5_args(t_stack**a, t_stack**b)
{
	low_median_push_b(a, b, ft_smallest(a)->content, ft_biggest(a)->content);
	sort_3_args(a);
	if (check_order(*b))
		sb(b);
	while ((*b))
		pa(a, b);
	free_stack(a);
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
