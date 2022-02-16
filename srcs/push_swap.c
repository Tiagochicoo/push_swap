/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/16 21:56:40 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*pop_head(t_list**head)
{
	t_list	*temp;

	temp = *head;
	if (head == NULL || *head == NULL)
		return (NULL);
	*head = (*head)->next;

	return (temp);
}

void	small_sort(t_list*a, t_list*b)
{
	int		max;
	int		min;
	int		content;
	int		next_content;

	min = (int)find_min(a);
	max = (int)find_max(a);
	while (!check_order(a))
	{
		content = a->content;
		next_content = a->next->content;
		if (content == max && next_content == min)
			ra(a);
		else if ((content == min && next_content == max)
			|| (content > next_content))
			sa(a);
		// else
		// 	rra(a, b);
	}
}


int main(int argc, char** argv)
{
	t_list	*a;
	t_list	*b;

	a = init_a(argc, argv);
	b = (t_list*)malloc(sizeof(t_list));
	if (check_args(argc, argv) && !check_order(a))
	{
		if (argc < 2)
			ft_putendl_fd("Error", 2);
		else if (argc < 5)
			small_sort(a, b);
		// else if (argc < 7)
		// 	medium_sort(a, b);
		// else
		// 	big_sort(a, b);
	}
	return (0);
}
