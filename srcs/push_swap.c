/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/24 17:49:46 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_list*head, char**stack_name)
{
	t_list	*ptr;

	ptr = head;
	printf("Stack %s\n", *stack_name);
	while (ptr)
	{
		printf("%d —> ", ptr->content);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

t_list	*pop_head(t_list**head)
{
	t_list	*temp;

	temp = *head;
	if (head == NULL || *head == NULL)
		return (NULL);
	*head = (*head)->next;
	return (temp);
}

t_list	*sort_stack(t_list**a, t_list**b)
{
	t_list	*temp;

	*b = NULL;
	while(a != NULL && *a != NULL)
	{
		if (b == NULL && (*b)->content == NULL)
		{
			if ((*a)->content > (*a)->next->content)
			{
				sa(a);
				printf("sa\n");
			}
			*b = ft_lstnew(pop_head(a)->content);
			printf("pb\n");
		}
		else
		{
			
				temp = pop_head(a);
				while (*b != NULL && (*b)->content > temp->content)
				{
					pa(a, b);
					printf("sa\n");
					//print_stack(*a, "A");
					//print_stack(*b, "B");
				}
				ft_lstadd_front(b, temp);
				printf("pb\n");
				//print_stack(*a, "A");
				//print_stack(*b, "B");

		}
	}
	while (b != NULL && *b != NULL)
	{
		if (a == NULL)
		{
			if ((*b)->content < (*b)->next->content)
				sa(b);
			*a = ft_lstnew(pop_head(b)->content);
			printf("pa\n");
		}
		else
		{
			temp = pop_head(b);
			while ((*a) != NULL && (*a)->content < temp->content)
			{
				pa(b, a);
				printf("sb\n");
				//print_stack(*a, "A");
				//print_stack(*c, "c");
			}
			ft_lstadd_front(a, temp);
			printf("pa\n");
			//print_stack(*a, "A");
			//print_stack(*b, "B");
		}
	}
}

int main(int argc, char** argv)
{
	t_list	*a;
	t_list	*b;

	a = init_a(argc, argv);
	b = (t_list*)malloc(sizeof(t_list));
	if (argc < 2)
		write(1, "ERROR: not enough parameters", 28);
	else if (check_args(argc, argv))
	{
		fill_props(a, argc);
		sort_stack(&a, &b);
	}
	return (0);
}
