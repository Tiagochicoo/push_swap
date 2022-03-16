/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/16 20:22:46 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	up_down(t_stack*b, int min)
{
	t_stack *temp;
	t_stack	*temp2;
	int		med;
	int		count;

	med = ft_stack_median(&b);
	temp = ft_stackdup(b);
	temp2 = temp;
	while (temp->next && temp->content != min && count++)
		temp = temp->next;
	if (count > ft_stacksize(b))
	{
		free(temp2);
		return (1);
	}
	free(temp2);
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

int	top_median_push_a(t_stack**b, t_stack**a)
{
	int	mid;
	int	med;
	int	flag;
	int	count;

	count = 0;
	mid = ft_stacksize(*b) / 2;
	med = ft_stack_median(b);
	while (mid > 0)
	{
		if (mid == 1 && flag++ == 2)
			return (count);
		if ((*b)->content > med && mid-- && ft_stacksize(*b) > 1 && count++)
			pa(a, b);
		else if ((*b)->content == ft_smallest(b))
		{
			pa(a, b);
			ra(a);
		}
		else
			rb(b);
		if (count == 1)
			count = (*a)->content;
	}
	return (count);
}

void	low_median_push_b(t_stack**a, t_stack**b, int stop)
{
	int			mid;
	int			med;
	static int	flag = 0;

	mid =  ft_stacksize(*a) / 2;
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

	flag = 0;
	min = ft_smallest(a);
	mid = (ft_stacksize(*a) / 2);
	med = ft_stack_median(a);
	if ((*a)->next->content == stop)
		flag++;
	if (flag == 1)
		return ;
	while (mid > 0 && (*a)->content != stop && (*a)->content != min)
	{
		if ((*a)->content > med && mid--)
			pb(b, a);
		else
			ra(a);
	}
}
