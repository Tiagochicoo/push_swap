/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/22 17:21:27 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	up_down(t_stack*b, int min)
{
	t_stack	*temp;
	t_stack	*head;
	int		count;

	count = 0;
	temp = ft_stackdup(b);
	head = temp;
	while (temp->next && temp->content != min && count++)
		temp = temp->next;
	if (count > ft_stacksize(b))
	{
		free_stack(&head);
		return (1);
	}
	free_stack(&head);
	return (0);
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
		if (mid == 1 && flag++ == 1)
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
	while (mid > 0)
	{
		if (mid == 1 && flag++ == 1)
			return ;
		if ((*b)->content > med && mid-- && ft_stacksize(*b) > 1)
			pa(a, b);
		else if ((*b)->content == ft_smallest(b)
			&& (*b)->content < (*a)->content)
		{
			pa(a, b);
			ra(a);
		}
		else
			rb(b);
	}
}

void	low_median_push_b(t_stack**a, t_stack**b, int stop)
{
	int			mid;
	int			med;
	static int	flag = 0;

	mid = ft_stacksize(*a) / 2;
	med = ft_stack_median(a);
	if ((*a)->next->content == stop && flag++ == 1)
		return ;
	while (mid > 0 && (*a)->content != stop)
	{
		if ((*a)->content < med && mid--)
			pb(b, a);
		else
			ra(a);
	}
}

void	top_median_push_b(t_stack**a, t_stack**b, int stop)
{
	int	mid;
	int	med;
	int	flag;
	int	min;
	int	content;

	flag = 0;
	min = ft_smallest(a);
	mid = (ft_stacksize(*a) / 2);
	med = ft_stack_median(a);
	content = (*a)->content;
	if (content == stop && flag++ == 2)
		return ;
	while (mid > 0 && content != stop && content != min)
	{
		if ((*a)->content > med && mid--)
			pb(b, a);
		else
			ra(a);
		content = (*a)->content;
	}
}
