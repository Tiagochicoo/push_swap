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

t_props	*fill_props(t_list*a, int argc)
{
	t_props	*props;
	t_list	*temp;
	int		i;
	int		*index;

	i = 0;
	temp = a;
	index = (int*)malloc(sizeof(int) * (argc - 1));
	props = (t_props*)malloc(sizeof(t_props));
	props->arg_count = argc - 1;
	while (temp->next != NULL)
	{
		index[i] = (int)temp->content;
		temp = temp->next;
		i++;
	}
	index[i] = (int)temp->content;
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
//
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
	int		*content;
	t_list	*head;
	t_list	*temp;

	i = 1;
	content = (int*)malloc(sizeof(int));
	while (i < argc)
	{
		*content = ft_atoi(argv[i]);
		temp = ft_lstnew(&content);
		ft_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}
