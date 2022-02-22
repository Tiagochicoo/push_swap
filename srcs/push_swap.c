/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/22 23:01:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack*a, t_stack*b)
{
	int			size;
	static int	min = INT_MIN;
	static int	max = INT_MAX;
	static int	count = 0;
	int			median;

	if (count > 5000)
		return ;
	median = ft_stack_median(&a);
	if (min < median)
	{
		if (!b)
			low_median_push_b(&a, &b, min);
		if (ft_stacksize(b) > 20)
			top_median_push_a(&b, &a);
		else
			min = order_in_b(&a, &b);
	}
	else
	{
		if (!b)
			top_median_push_b(&a, &b, max);
		if (ft_stacksize(b) > 20)
			low_median_push_a(&b, &a);
		else
			max = order_in_b(&a, &b);
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
