/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/20 16:55:13 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stack**b, t_stack**a)
{
	t_stack	*temp;

	temp = *a;
	if (*a == NULL)
		return;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_putendl_fd("pb", 2);
}

void	sb(t_stack**head)
{
	t_stack *temp;

	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	ft_putendl_fd("sb", 2);
}

