/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/31 18:53:25 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case_1(t_stack*temp, t_stack*first, t_stack*third)
{
	if (third < first)
			sa(&temp);
	else
		ft_printf("sa\n");
}

void	sort_3_args(t_stack**a)
{
	void		*first;
	void		*second;
	void		*third;

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
