/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/20 16:54:57 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack**a, t_stack**b)
{
	t_stack	*temp;

	temp = *b;
	if (*b == NULL)
		return;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	ft_putendl_fd("pa", 2);
}

void	sa(t_stack**head)
{
	t_stack *temp;

	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	ft_putendl_fd("sa", 2);
}

void	ra(t_stack**head)
{
	t_stack *first;
	t_stack *last;

	first = *head;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	last->next = first;
	ft_putendl_fd("ra", 2);
}

void	rra(t_stack**a)
{
	t_stack *last;
	t_stack *sec_last;

	last = (*a);
	sec_last = NULL;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = (*a);
	(*a) = last;	
	ft_putendl_fd("rra", 2);
}
