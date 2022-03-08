/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/08 19:42:20 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack*a, t_stack*b)
{
	int			size;
	int			ra_count;
	static int	count = 0;

	if (count > 5000)
		return ;
	ra_count = 0;
	if (!b)
		ra_count = low_median_push_b(&a, &b);
	while (ra_count-- > 0 && count > 1)
		rra(&a);
	if (ft_stacksize(b) > 20)
		top_median_push_a(&b, &a);
	if (ft_stacksize(b) <= 20)
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
		else if (argc < 7)
			sort_5_or_less(a, b);
		else
			sort_stack(a, b);
	}
	else
		free_stack(&a);
	return (0);
}
