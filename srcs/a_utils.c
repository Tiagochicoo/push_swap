/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/19 13:39:13 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack**a, t_stack**b)
{
	t_stack	*temp;

	temp = *b;
	if (*b == NULL)
		return ;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	// ft_putendl_fd("pa", 2);
	write(1, "pa\n", 3);
}

void	sa(t_stack**head)
{
	t_stack	*temp;

	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	write(1, "sa\n", 3);
}

void	ra(t_stack**head)
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
	write(1, "ra\n", 3);
}

void	rra(t_stack**a)
{
	t_stack	*last;
	t_stack	*sec_last;

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
	write(1, "rra\n", 4);
}

void	rr_s(t_stack**head)
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
}

void	rr(t_stack**a, t_stack**b)
{
	rr_s(a);
	rr_s(b);
	ft_putendl_fd("rr", 2);
}
