/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/21 20:55:45 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack*a, t_stack*b)
{
	int	size;
	int	flag;

	flag = 0;
	low_median_push_b(&a, &b);
	size = ft_stacksize(b);
	while (size > 3)
	{
		top_median_push_a(&b, &a);
		size = ft_stacksize(b);
	}
	order_in_b(&a, &b, 3);
	while(flag++ < 100)
		order_in_b(&a, &b, 15);
	free_stack(&a);

	// while (b)
	// 	pa(&a, &b);
	//quarter_push_b(&a, &b);
	//sort_3_args(&a);
	// while (ft_stacksize(b) > 3)
	// 	median_push_a(&b, &a);
	// sort_3_args(&b);
	// quarter_push_b(&a, &b);
	// quarter_push_a(&b, &a);
	return ;
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
