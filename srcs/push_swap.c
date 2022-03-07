/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/05 12:48:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack*a, t_stack*b)
{
	int			size;
	static int	min = INT_MIN;
	static int	max = INT_MAX;
	static int	count = 0;
	static int	median = 0;
	static int	num_to_push = 0;
	t_stack		*to_order;

	if (count > 5000)
		return ;
	if (count == 0)
	{
		min = ft_smallest(&a)->content;
		median = ft_stack_median(&a);
		num_to_push = ft_count_to_push(a, median, min);
		to_order = ft_to_order(a);
	}
	if (!b)
	{
		low_median_push_b(&a, &b, num_to_push, median, min);
		median = ft_stack_median(&a);
	}
	if (ft_stacksize(b) > 20)
	{
		top_median_push_a(&b, &a);
		median = ft_stack_median(&a);
		num_to_push = ft_count_to_push(a, median, min);
	}
	if (ft_stacksize(b) <= 20)
		min = order_in_b(&a, &b);
	
	
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
