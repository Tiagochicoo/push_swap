/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/20 23:09:59 by tpereira         ###   ########.fr       */
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

void	median_push_a(t_stack**src, t_stack**dest)
{
	int	mid;
	int	med;

	mid = ft_stacksize(*src) / 2;
	med = ft_stack_median(src);
	while (mid)
	{
		if ((*src)->content < med)
		{
			mid--;
			pa(dest, src);
		}
		else
			rb(src);
	}
}

void	median_push_b(t_stack**src, t_stack**dest)
{
	int	mid;
	int	med;

	mid = ft_stacksize(*src) / 2;
	med = ft_stack_median(src);
	while (mid)
	{
		if ((*src)->content < med)
		{
			mid--;
			pb(dest, src);
		}
		else
			ra(src);
	}
}

void	quarter_push_a(t_stack**src, t_stack**dest)
{
	int	qrt;
	int	med;

	qrt = ft_stacksize(*src) / 4;
	med = ft_stack_quarter(src);
	while (qrt)
	{
		if ((*src)->content < med)
		{
			qrt--;
			pa(dest, src);
		}
		else
			rb(src);
	}
}

void	quarter_push_b(t_stack**src, t_stack**dest)
{
	int	qrt;
	int	med;

	qrt = ft_stacksize(*src) / 4;
	med = ft_stack_quarter(src);
	while (qrt)
	{
		if ((*src)->content < med)
		{
			qrt--;
			pb(dest, src);
		}
		else
			ra(src);
	}
}
