/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:05:11 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/23 22:39:25 by tpereira         ###   ########.fr       */
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
	while (temp->content || temp->content == 0)
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

int	ft_stack_median(t_stack**head, int min, int max)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		med;
	int		mid;

	temp = ft_stackdup(*head);
	temp2 = temp;
	ft_stacksort(temp);
	while (temp->content < min || temp->content > max && temp->next)
		temp = temp->next;
	mid = ft_stacksize(temp) / 2;
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

int	order_in_b(t_stack**a, t_stack**b, int min_a)
{
	int	min;
	int	size;
	int	smallest;
	
	min = 0;
	smallest = 0;	
	while (*b)
	{
		min = ft_smallest(b)->content;
		if (ft_stacksize(*b) == 1 && (*b)->content > min_a)
			pa(a, b);
		while ((*b) && (*b)->content > min)
			rb(b);
		while ((*b) && (*a)->content < (*b)->content)
			ra(a);
		if (ft_stacksize(*b) > 1)
		{
			pa(a, b);
			smallest = (*a)->content;
			ra(a);
		}
	}
	return (smallest);
}
