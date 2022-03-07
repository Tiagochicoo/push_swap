/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:05:11 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/07 20:06:33 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_biggest(t_stack**head)
{
	t_stack	*temp;
	int		biggest;

	temp = *head;
	biggest = INT_MIN;
	while (temp->next != NULL)
	{
		if (temp->content > biggest)
			biggest = temp->content;
		temp = temp->next;
	}
	return (ft_stacknew(biggest));
}

t_stack	*ft_smallest(t_stack**head)
{
	t_stack	*temp;
	int		smallest;

	smallest = INT_MAX;
	temp = *head;
	while (temp && temp->next != NULL)
	{
		if (temp->content < smallest)
			smallest = temp->content;
		if (temp->next != NULL)
			temp = temp->next;
		else
			return (ft_stacknew(smallest));
	}
	return (ft_stacknew(smallest));
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

void	order_in_b(t_stack**a, t_stack**b)
{
	int	min;
	
	min = 0;
	while (*b)
	{
		min = ft_smallest(b)->content;
		while ((*b)->content > min)
			rb(b);
		pa(a, b);
		ra(a);
	}
}
