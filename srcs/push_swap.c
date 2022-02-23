/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/23 22:34:19 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack*a, t_stack*b)
{
	int			biggest;
	int			median;
	static int	min = INT_MIN;
	static int	max = INT_MAX;
	static int	safe = 0; 
	static int	ra_count = 0; //RA count

	biggest = ft_biggest(&a)->content;
	if (min == biggest) //BASE CASE
		return ;
	if (safe > 5000) // JUST FOR TESTING RECURSION PROTECTION
		return ;
	median = ft_stack_median(&a, min, max);
	if (min < median)
	{
		if (!b)
			ra_count = low_median_push_b(&a, &b, min, max);
		if (ft_stacksize(b) > 20)
			min = top_median_push_a(&b, &a, min);
		else
			min = order_in_b(&a, &b, min);
	}

	
	safe++;
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
