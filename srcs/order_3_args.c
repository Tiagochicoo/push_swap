/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_3_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2021/12/21 18:31:18 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		compare_args(void*one, void*two)
{
	if (one > two)
		return (0);
	return (1);
}

void	order_3_args(t_list *a)
{
	t_list	*current;

	current = a;
	while (current->next != NULL)
	{
		if (compare_args(current->content, current->next->content))
		{
			print_args(a);
			sa(current);
			print_args(a);
		}
		current = current->next;
	}
}