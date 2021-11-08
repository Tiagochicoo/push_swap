/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:47:47 by tpereira          #+#    #+#             */
/*   Updated: 2021/11/08 18:52:00 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	convert_to_int(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp != NULL)
	{
		temp->content = (int)ft_atoi(temp->content);
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