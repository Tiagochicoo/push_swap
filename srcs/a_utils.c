/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:47:09 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/17 20:08:17 by tpereira         ###   ########.fr       */
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
	int	temp;

	temp = head->content;
	head->content = head->next->content;
	head->next->content = temp;
	ft_putendl_fd("sa", 2);
}

void	ra(t_list**head)
{
	t_list	*first;
	t_list	*last;

	first = *head;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	*head = first->next;
	last->next = first;
	first->next = NULL;
	ft_putendl_fd("ra", 2);
}

void	rra(t_list*a)
{
	t_list *last;
	t_list *sec_last;

	last = a;
	sec_last = NULL;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = a;
	a = last;	
	ft_putendl_fd("rra", 2);
}
