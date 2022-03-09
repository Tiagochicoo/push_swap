/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/09 22:24:49 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack*a, t_stack*b)
{
	int			biggest;
	static int	min = INT_MIN;
	static int	count = 0;
	int			median;
	int			quarter;
	static int	stop = INT_MAX;

	quarter = ft_stacksize(a) / 4;
	biggest = ft_biggest(&a)->content;
	if (min == biggest) //BASE CASE
		return ;
	if (count > 5000) // JUST FOR TESTING RECURSION PROTECTION
		return ;
	median = ft_stack_median(&a);
	if (min < median)
	{
		if (!b)
		{
			low_median_push_b(&a, &b, stop);
			stop = a->content;
		}
		if (ft_stacksize(b) > quarter)
			top_median_push_a(&b, &a);
		else
			order_in_b(&a, &b);
	}
	count++;
	if (!check_order(a))
		sort_stack(a, b);
}

int	main(int argc, char**argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	a = init_a(argc, argv, a);
	if (check_args(argc, argv) && !check_order(a))
	{
		if (argc < 2)
			return (0);
		else if (argc < 7)
			sort_5_or_less(a, b);
		else
			sort_stack(a, b);
	}
	else
		free_stack(&a);
	return (0);
}
