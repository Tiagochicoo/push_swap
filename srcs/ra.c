/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/19 17:49:40 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list *head)
{
	t_list *last;
	t_list *sec_last;

	last = head;
	while (last->next->next != NULL)
		last = last->next;
	sec_last = last->next;
	last->next = head->next;
	head = last->next;
	head->next = NULL;
}
