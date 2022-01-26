/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:28:08 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/26 16:21:04 by tpereira         ###   ########.fr       */
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
	printf("pa\n");
}
