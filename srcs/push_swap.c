/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2021/11/03 09:21:33 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_args(t_list *head)
{
	t_list *temp = head;

	while (temp != NULL)
	{
		printf("%d\n", (int *)temp->content);
		temp = temp->next;
	}
}

t_list	*init_a(int argc, char** argv)
{
	int		i;
	t_list	*head;
	t_list	*temp;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		temp = ft_lstnew(argv[i]);
		ft_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}

int main(int argc, char** argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		write(1, "ERROR: not enough parameters", 28);
	else if (argc >= 2)
	{
		if (check_args(argc, argv) == 1)
		{
			a = init_a(argc, argv);
			b = NULL;
			convert_to_int(a);
			print_args(a);
		}
	}
	return (0);
}