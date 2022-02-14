/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:05:11 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/14 18:54:30 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*find_max(t_list*list)
{
	void	*max;

	if(!list)
		return (NULL);
	max = list->content;
	while (list)
	{
		if (*(int *)list->content > *(int *)max)
			max = list->content;
		list = list->next;
	}
	return (max);
}

void	*find_min(t_list*list)
{
	void	*min;

	if (!list)
		return (NULL);
	min = list->content;
	while (list)
	{
		if (*(int *)list->content < *(int * )min)
			min = list->content;
		list = list->next;
	}
	return (min);
}
