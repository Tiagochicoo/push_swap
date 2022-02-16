/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:39:55 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/16 16:49:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	small_sort(t_stack*a, t_stack*b)
{
	int		max;
	int		min;
	void	*content;
	void	*next_content;

	min = (int*)find_min(a->head);
	max = (int*)find_max(a->head);
	while (!check_order(a->head))
	{
		content = a->head->content;
		next_content = a->head->next->content;
		if ((int *)content == max && (int *)next_content == min)
			ra(a, b);
		else if (((int *)content == min && (int *)next_content == max)
			|| ((int *)content > (int *)next_content))
			sa(a, b);
		else
			rra(a, b);
	}
}