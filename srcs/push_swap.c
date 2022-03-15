/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/15 15:48:18 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_6(t_stack*a, t_stack*b)
{

}

void	sort_stack(t_stack*a, t_stack*b)
{
	static int	count = 0;
	static int	stop = INT_MAX;
	static int	stop2 = INT_MAX;
	int			quarter;

	quarter = ft_stacksize(a) / 4;
	if (count > 5000) // JUST FOR TESTING RECURSION PROTECTION
		return ;
	if (!b && !check_order(a))
	{
		if (count < 50)
		{
			low_median_push_b(&a, &b, stop);
			stop = a->content;
		}
		else
		{
			top_median_push_b(&a, &b, stop2);
			stop2 = a->content;
		}
	}
	if (ft_stacksize(b) > 20)
		top_median_push_a(&b, &a);
	else
		order_in_b(&a, &b);
	
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
		else if (argc <= 7)
			sort_5_or_less(a, b);
		else
			sort_stack(a, b);
	}
	free_stack(&a);
	return (0);
}
