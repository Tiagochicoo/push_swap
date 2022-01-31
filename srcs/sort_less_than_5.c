/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/31 19:28:41 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2_args(t_stack*head)
{
	int	one;
	int	two;

	one = head->content;
	two = head->next->content;
	if (one > two)
		sa(&head);
}

void	sort_less_than_5(t_stack*a, t_stack*b)
{
	int	size;

	size = ft_stacksize(a);
	if (size == 2)
		sort_2_args(a);
	else if (size == 3)
		sort_3_args(&a);
	else if (size == 4)
	 	sort_4_args(&a, &b);
	// else if (size == 5)
	// 	sort_5_args(a);
}
