/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/26 18:17:22 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_list*head, char**stack_name)
{
	t_list	*temp;

	temp = head;
	printf("Stack %s\n", *stack_name);
	while (temp)
	{
		printf("%d —> ", temp->content);
		temp = temp->next;
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

void	sort_list(t_list**a, t_list**b)
{
	t_list	*temp;

	*b = NULL;
	while(a != NULL && *a != NULL && check_order(*a))
	{
		if (*b == NULL)
		{
			if ((*a)->content > (*a)->next->content)
				sa(a);
			*b = ft_lstnew((void*)pop_head(a)->content);
			printf("pb\n");
		}
		else
		{
			temp = pop_head(a);
			while (*b != NULL && (*b)->content > temp->content)
			{
				pa(a, b);
				printf("sa\n");
			}
			ft_lstadd_front(b, temp);
			printf("pb\n");
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
				//print_list(*a, "A");
				//print_list(*c, "c");
			}
			ft_lstadd_front(a, temp);
			printf("pa\n");
			//print_list(*a, "A");
			//print_list(*b, "B");
		}
	}
}

int main(int argc, char** argv)
{
	t_list	*a;
	t_list	*b;
	t_props *props;

	a = init_a(argc, argv);
	b = (t_list*)malloc(sizeof(t_list));
	props = (t_props*)malloc(sizeof(t_props));
	if (argc < 2)
		return (0);
	else if (check_args(argc, argv) && check_order(a))
	{
		//props = fill_props(a, argc);
		sort_list(&a, &b);
	}
	return (0);
}
