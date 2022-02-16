/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:49:17 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/16 21:56:10 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_list *head)
{
	int		count;
	t_list	*current;

	current = head;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	find_min(t_list*list)
{
	int		min;
	t_list	*temp;

	temp = list;
	if (!temp)
		return (NULL);
	min = temp->content;
	while (temp)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

int	find_max(t_list*list)
{
	int		max;
	t_list	*temp;

	temp = list;
	if(!temp)
		return (NULL);
	max = temp->content;
	while (temp)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	return (max);
}
