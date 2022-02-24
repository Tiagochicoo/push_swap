/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/24 15:31:47 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack*a, t_stack*b)
{
	int			biggest;
	int			median;
	static int	chunk_min = INT_MIN;
	static int	chunk_max = INT_MAX;
	static int	safe = 0;
	static int	ra_count = 0; //RA count

	biggest = ft_biggest(&a)->content;
	if (chunk_min == biggest) //BASE CASE
		return ;
	if (safe > 5000) // JUST FOR TESTING RECURSION PROTECTION
		return ;
	median = ft_stack_median(&a, chunk_min, chunk_max);
	if (chunk_min < median)
	{
		if (!b)
			low_median_push_b(&a, &b, chunk_min, chunk_max);
		if (ft_stacksize(b) > 20)
			chunk_min = top_median_push_a(&b, &a, chunk_min);
		else
			chunk_min = order_in_b(&a, &b, chunk_min);
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
