/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/01 19:11:08 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack**a, t_stack**b)
{
	t_stack	*new;

	new = *b;			// top of B stack
	if (*b == NULL)
		return;
	*b = (*b)->next; 	// Advance the B stack Head pointer
	new->next = *a;		// Link the old A stack Head with the new A stack Head
	*a = new;			// move A stack Head by 1 node
	printf("pa\n");
}
