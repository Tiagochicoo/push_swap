/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_or_less.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/20 16:08:13 by tpereira         ###   ########.fr       */
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
	int	mid;
	int	med;

	mid = ft_stacksize(*a) / 2;
	med = ft_stack_median(a);
	while (mid)
	{
		if ((*a)->content < med)
		{
			mid--;
			pb(b, a);
		}
		else
			ra(a);
	}
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
