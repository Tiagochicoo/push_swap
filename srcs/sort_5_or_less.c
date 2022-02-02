/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_or_less.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/02 20:17:38 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stop_loop(t_stack*stack, t_stack*head)
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

void	sort_2_args(t_stack*head)
{
	int	one;
	int	two;

	one = head->content;
	two = head->next->content;
	if (one > two)
		sa(&head);
}

int	is_ordered_loop(t_stack**head)
{
	int		size;
	int		flag;
	int		moves;
	t_stack	*loop;

	size = ft_stacksize(*head) + 1;
	loop = *head;
	flag = 0;
	moves = 0;
	while (loop->next != NULL)
		loop = loop->next;
	loop->next = *head;
	while (flag < 2 && moves < size)
	{
		if (loop->content > loop->next->content)
			flag++;
		loop = loop->next;
		moves++;
	}
	if (flag >= 2)
		moves = 0;
	stop_loop(*head, *head);
	return (moves);
}

void	sort_5_args(t_stack**a, t_stack**b)
{
	int	moves;

	moves = is_ordered_loop(a);
	if (moves == 1)
		ra(a);
	else if (moves == 0)
	{
		while (!check_order(*a))
		{
			pb(b, a);
			pb(b, a);
			if (check_order(*b))
				sb(b);
			sort_3_args(a);
			pa(a, b);
			sort_4_args(a, b);
			pa(a, b);
			//ra(a);
		}
	}
	else
		while (!check_order(*a))
			ra(a);
}

void	sort_5_or_less(t_stack*a, t_stack*b)
{
	int	size;

	size = ft_stacksize(a);
	if (size == 2)
		sort_2_args(a);
	else if (size == 3)
		sort_3_args(&a);
	else if (size == 4)
		sort_4_args(&a, &b);
	else if (size == 5)
		sort_5_args(&a, &b);
}
