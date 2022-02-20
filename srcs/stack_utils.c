/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:05:11 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/20 16:06:28 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


t_stack	*ft_biggest(t_stack**head)
{
	t_stack	*temp;
	int 	biggest;

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
	while (temp->next != NULL)
	{
		if (temp->content < smallest)
			smallest = temp->content;
		temp = temp->next;
	}
	return (ft_stacknew(smallest));
}

int	ft_stack_median(t_stack**head)
{
	t_stack	*temp;
	int		med;
	int		mid;

	med = 0;
	mid = ft_stacksize(*head) / 2;
	temp = ft_stackdup(*head);
	ft_stacksort(temp);
	while (mid--)
		temp = temp->next;
	med = temp->content;
	free_stack(&temp);
	return (med);
}

void	ft_stacksort(t_stack*head)
{
	t_stack	*temp;

	temp = head;
	while(head->next)
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

int	check_loop_order(t_stack *a, int size)
{
	int		i;
	int		flag;
	t_stack	*temp;

	i = 0;
	flag = 0;
	temp = a;
	if (a == NULL)
		return (0);
	while (temp->next != NULL && i < size)
	{
		if (temp->content > temp->next->content)
			flag++;
		temp = temp->next;
		if (flag > 1)
			return (0);
		i++;
	}
	return (1);
}

void	start_loop(t_stack**head)
{
	t_stack	*temp;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
}

void	stop_loop(t_stack*head)
{
	int		i;
	t_stack	*ptr1;
	t_stack	*ptr2;

	i = 1;
	ptr1 = head;
	ptr2 = head;
	while (ptr1->next != ptr2)
	{
		ptr1 = ptr1->next;
		i++;
	}
	ptr1 = head;
	ptr2 = head;
	while (i-- != 1)
		ptr2 = ptr2->next;
	ptr2->next = NULL;
}

int	is_ordered_loop(t_stack**head)
{
	int	size;

	size = ft_stacksize(*head);
	start_loop(head);
	if (check_loop_order(*head, size))
	{
		stop_loop(*head);
		return (1);
	}
	else
	{
		stop_loop(*head);
		return (0);
	}
}