/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:47:47 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/25 16:32:27 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_props	*fill_props(t_stack*a, int argc)
{
	t_props *props;
	t_stack	*temp;
	int		i;
	int		index[argc - 1];

	i = 0;
	temp = a;
	props = (t_props*)malloc(sizeof(t_props));
	props->arg_count = argc - 1;
	while (temp->next != NULL)
	{
		index[i] = temp->content;
		temp = temp->next;
		i++;
	}
	index[i] = temp->content;
	return (props);
}

int	stack_size(t_stack *head)
{
	int		count;
	t_stack	*current;

	current = head;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

// void	convert_to_int(t_stack *a)
// {
// 	int		i;
// 	t_stack	*temp;

// 	temp = a;
// 	i = (int)malloc(sizeof(int));
// 	while (temp != NULL)
// 	{
// 		i = ft_atoi(temp->content);
// 		temp->content = i;
// 		temp = temp->next;
// 	}
// }

t_stack	*init_a(int argc, char**argv)
{
	int		i;
	t_stack	*head;
	t_stack	*temp;

	i = 1;
	//head = (t_stack*)malloc(sizeof(t_stack));
	while (i < argc)
	{
		temp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}
