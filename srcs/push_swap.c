/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/24 19:29:57 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack*head, char**stack_name)
{
	t_stack	*ptr;

	ptr = head;
	printf("Stack %s\n", *stack_name);
	while (ptr)
	{
		printf("%d —> ", ptr->content);
		ptr = ptr->next;
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

t_stack	*sort_stack(t_stack**a, t_stack**b)
{
	t_stack	*temp;

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
	t_stack	*a;
	t_stack	*b;
	t_props *props;

	a = init_a(argc, argv);
	b = (t_stack*)malloc(sizeof(t_stack));
	props = (t_props*)malloc(sizeof(t_props));
	if (argc < 2)
		write(1, "ERROR: not enough parameters", 28);
	else if (check_args(argc, argv))
	{
		props = fill_props(a, argc);
		sort_stack(&a, &b);
	}
	return (0);
}
