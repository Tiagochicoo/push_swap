/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/16 15:00:46 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack*a, t_stack*b)
{
	static int	count = 0;
	static int	stop = INT_MAX;
	static int	stop2 = INT_MAX;

	if (count > 100)
		return ;
	if (count < 50)
		stop = sort_lower(&a, &b, stop);
	else
		stop2 = sort_top(&a, &b, stop2);
	count++;
	if (!check_order(a))
		sort_stack(a, b);
	else
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
		else if (argc <= 7)
			sort_5_or_less(a, b);
		else
			sort_stack(a, b);
	}
	free_stack(&a);
	return (0);
}
