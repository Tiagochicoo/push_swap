/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/20 16:38:49 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack*head, char**stack_name)
{
	t_stack	*temp;

	temp = head;
	printf("Stack %s\n", *stack_name);
	while (temp)
	{
		printf("%d —> ", temp->content);
		temp = temp->next;
	}
	printf("NULL\n");
}

t_stack	*pop_head(t_stack**head)
{
	t_stack	*temp;

	temp = *head;
	if (head == NULL || *head == NULL)
		return (NULL);
	*head = (*head)->next;
	return (temp);
}

void	sort_stack(t_stack*a, t_stack*b)
{
	t_stack	*temp;

	
}

int main(int argc, char** argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	a = init_a(argc, argv, a);
	if (check_args(argc, argv) && !check_order(a))
	{
		if (argc < 2)
			return (0);
		else if (argc < 7)
			sort_5_or_less(a, b);
		else
			sort_stack(a, b);
	}
	return (0);
}
