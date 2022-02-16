/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:47:09 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/16 22:11:15 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_list**a, t_list**b)
{
	t_list	*new;

	new = *b;			// top of B stack
	if (*b == NULL)
		return;
	*b = (*b)->next; 	// Advance the B stack Head pointer
	new->next = *a;		// Link the old A stack Head with the new A stack Head
	*a = new;			// move A stack Head by 1 node
	ft_putendl_fd("pa", 2);
}

void	sa(t_list*head)
{
	t_list *temp;

	temp = head;
	head = head->next;
	temp->next = head->next;
	head->next = temp;
	ft_putendl_fd("sa", 2);
}

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
	ft_putendl_fd("ra", 2);
}
