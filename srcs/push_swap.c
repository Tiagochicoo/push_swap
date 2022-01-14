/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/14 21:01:29 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_list*head, char**stack_name)
{
    t_list *ptr; 
	
	ptr = head;
	printf("Stack %s\n", stack_name);
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
		return;
	*head = (*head)->next;

	return (temp);
}

t_list	*sort_stack(t_list**a, t_list**b)
{
	t_list	*temp;

	while(a != NULL && *a != NULL)
	{
		if (b == NULL || (*b)->content == NULL)
		{
			*b = ft_lstnew(pop_head(a)->content);
			//printf("pb\n");
		}
		else
		{
			temp = pop_head(a);
			//printf("pb\n");
			while ((*b) != NULL && (*b)->content > temp->content)
			{
				pa(a, b);
				//print_stack(*a, "A");
				//print_stack(*b, "B");
			}
			ft_lstadd_front(b, temp);
			//print_stack(*a, "A");
			//print_stack(*b, "B");
		}
	}
	while (b != NULL && *b != NULL)
		pa(a, b);
	//printf("loop ended\n");
	// while (b != NULL)
	// 	pa(a, b);
	// if (check_order(a))
	// 	print_args(a);
	// else
	// 	printf("not ordered...");
}

int main(int argc, char** argv)
{
	t_list	*a;
	t_list	*b;

	a = init_a(argc, argv);
	b = (t_list*)malloc(sizeof(t_list));
	//convert_to_int(a);
	if (argc < 2)
		write(1, "ERROR: not enough parameters", 28);
	else if (check_args(argc, argv))
		sort_stack(&a, &b);
	print_stack(a, "A");
	print_stack(b, "B");
	return (0);
}