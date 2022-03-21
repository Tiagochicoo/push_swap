/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/21 18:39:14 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack**a, t_stack*b)
{
	static int	count = 0;
	t_stop		*stop;
	static int	stop2 = INT_MAX;
	int			i;

	i = 15;
	if (ft_stacksize(*a) > 120)
		i = 20;
	stop = init_stop(stop);
	while (!check_order(*a))
	{
		if (count > 1000)
			return ;
		if (count < i)
			sort_lower(a, &b, stop, i);
		else
			stop2 = sort_top(a, &b, stop2, i);
		count++;
	}
	free(stop);
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
			a = sort_5_or_less(a, b);
		else
			sort_stack(&a, b);
	}
	free_stack(&a);
	return (0);
}
