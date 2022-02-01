/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_or_less.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/01 20:47:46 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int		i;
	int		flag;
	t_stack	*loop;

	i = ft_stacksize(*head) + 1;
	loop = *head;
	flag = 0;
	while (loop->next != NULL)
		loop = loop->next;
	loop->next = *head;
	while (i-- != 0 && flag < 2)
	{
		if (loop->content > loop->next->content)
			flag++;
		loop = loop->next; //LAST
	}
	if (flag == 2)
		return (0);
	return (1);
}

//https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

void	sort_5_args(t_stack**a, t_stack**b)
{
	if (is_ordered_loop(a) == 1)
		ra(a);
	else
	{
		while (!check_order(*a))
		{
			pb(b, a);
			pb(b, a);
			if (check_order(*b))
				sb(b);
			sort_3_args(a);
		}
	}
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
