/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:47:47 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/26 16:19:42 by tpereira         ###   ########.fr       */
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

int	ft_stacksize(t_stack *lst)
{
	int		count;
	t_stack	*temp;

	temp = lst;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

t_stack	*init_a(int argc, char**argv, t_stack*a)
{
	int		i;
	int		content;

	i = 1;
	while (i < argc)
	{
		content = ft_atoi(argv[i]);
		ft_stackadd_back(&a, ft_stacknew(content));
		i++;
	}
	return (a);
}
