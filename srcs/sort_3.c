/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/03 18:42:39 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_args(t_stack**a)
{
	int		first;
	int		second;
	int		third;

	while (!check_order(*a))
	{
		first = (*a)->content;
		second = (*a)->next->content;
		third = (*a)->next->next->content;
		if (first > second && first > third && second < third)
			ra(a);
		else if (first < second && second > third)
			rra(a);
		else if (first > second && second < third)
			sa(a);
		else if (first > second && second > third)
			sa(a);
	}
}
