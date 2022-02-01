/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/01 19:41:48 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_4_args(t_stack**a, t_stack**b)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (!check_order(*a))
	{
		pb(b, a);
		sort_3_args(a);
		num = (*a)->content;
		while ((*b) != NULL)
		{
			while ((*a)->content < (*b)->content && i++ < 3)
				ra(a);
			pa(a, b);
		}
		while ((*a)->content != num)
			ra(a);
	}
}
