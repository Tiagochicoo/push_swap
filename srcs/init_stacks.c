/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:47:47 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/24 17:40:27 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_props	*fill_props(t_list*a, int argc)
{
	t_props *props;
	int		index[argc - 2];
	int		i;
	t_list	*temp;

	i = 0;
	temp = a;
	props = (t_props*)malloc(sizeof(t_props));
	props->arg_count = argc - 2;
	while (temp->next != NULL)
	{
		index[i] = temp->content;
		temp = temp->next;
		i++;
	}	
	return (props);
}

int	stack_size(t_list *head)
{
	int		count;
	t_list	*current;

	current = head;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

// void	convert_to_int(t_list *a)
// {
// 	int		i;
// 	t_list	*temp;

// 	temp = a;
// 	i = (int)malloc(sizeof(int));
// 	while (temp != NULL)
// 	{
// 		i = ft_atoi(temp->content);
// 		temp->content = i;
// 		temp = temp->next;
// 	}
// }

t_list	*init_a(int argc, char**argv)
{
	int		i;
	t_list	*head;
	t_list	*temp;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		temp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}
