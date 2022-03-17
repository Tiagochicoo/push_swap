/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:05:11 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/16 19:46:01 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_biggest(t_stack**head)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		biggest;

	temp = ft_stackdup(*head);
	temp2 = temp;
	biggest = INT_MIN;
	while (temp)
	{
		if (temp->content > biggest)
			biggest = temp->content;
		if (temp->next != NULL)
			temp = temp->next;
		else
			break ;
	}
	free_stack(&temp2);
	return (biggest);
}

int	ft_smallest(t_stack**head)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		smallest;

	smallest = INT_MAX;
	temp = ft_stackdup(*head);
	temp2 = temp;
	while (temp->content || temp->content == 0)
	{
		if (temp->content < smallest)
			smallest = temp->content;
		if (temp->next != NULL)
			temp = temp->next;
		else
		{
			free_stack(&temp2);
			return (smallest);
		}
	}
	free_stack(&temp2);
	return (smallest);
}

int	ft_stack_median(t_stack**head)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		med;
	int		mid;

	med = 0;
	mid = ft_stacksize(*head) / 2;
	temp = ft_stackdup(*head);
	temp2 = temp;
	ft_stacksort(temp);
	while (mid--)
		temp = temp->next;
	med = temp->content;
	free_stack(&temp2);
	return (med);
}

void	ft_stacksort(t_stack*head)
{
	t_stack	*temp;

	temp = head;
	while (head->next)
	{
		if (head->content > head->next->content)
		{
			ft_swap(&head->content, &head->next->content);
			head = temp;
		}
		else
			head = head->next;
	}
	head = temp;
}

t_stack	*ft_stackdup(t_stack*head)
{
	t_stack	*new;
	t_stack	*temp;

	new = NULL;
	while (head)
	{
		temp = ft_stacknew(head->content);
		if (!temp)
			return (0);
		ft_stackadd_back(&new, temp);
		head = head->next;
	}
	return (new);
}
