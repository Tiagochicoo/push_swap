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

void	convert_to_int(t_list *a)
{
	int		i;
	t_list	*temp;

	temp = a;
	i = (int)malloc(sizeof(int));
	while (temp != NULL)
	{
		i = ft_atoi(temp->content);
		temp->content = i;
		temp = temp->next;
	}
}

t_list	*init_a(int argc, char**argv)
{
	int		i;
	int		content;
	t_list	*head;
	t_list	*temp;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		content = ft_atoi(argv[i]);
		temp = ft_lstnew(content);
		ft_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}
