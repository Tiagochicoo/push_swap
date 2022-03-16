/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/16 14:36:01 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stack**b, t_stack**a)
{
	t_stack	*temp;

	temp = *a;
	if (*a == NULL)
		return ;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_putendl_fd("pb", 2);
}

void	sb(t_stack**head)
{
	t_stack	*temp;

	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	ft_putendl_fd("sb", 2);
}

void	rb(t_stack**head)
{
	t_stack	*first;
	t_stack	*last;

	first = *head;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	last->next = first;
	ft_putendl_fd("rb", 2);
}

void	rrb(t_stack**b)
{
	t_stack	*last;
	t_stack	*sec_last;

	last = (*b);
	sec_last = NULL;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = (*b);
	(*b) = last;
	ft_putendl_fd("rrb", 2);
}
