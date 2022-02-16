/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:05:11 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/16 18:55:01 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*find_max(t_list*list)
{
	void	*max;
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

void	*find_min(t_list*list)
{
	void	*min;
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

void	*find_med(t_list*list)
{
	void	*med;
	t_list	*temp;

	temp = list;
	if (!temp)
		return (NULL);
	med = temp->content;
	while (temp)
	{
		if (temp->content < med)
			med += (int)temp->content;
		temp = temp->next;
	}
	med /= (int*)ft_lstsize(list);
	return (med);
}
