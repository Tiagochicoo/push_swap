/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/31 19:27:33 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_4_args(t_stack**a, t_stack**b)
{
	while (!check_order(&a))
	{
		pb(b, a);
		pb(b, a);
		sort_2_args(a);
		sort_2_args(b);
		while ((*b) != NULL)
		{
			pa(a, b);
			ra(a);
		}		
	}
}
