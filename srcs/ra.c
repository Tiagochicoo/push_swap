/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/31 15:48:20 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *head)
{
	t_stack *last;
	t_stack *sec_last;

	last = head;
	while (last->next->next != NULL)
		last = last->next;
	sec_last = last->next;
	last->next = head->next;
	head = last->next;
	head->next = NULL;
	printf("RA");
}
