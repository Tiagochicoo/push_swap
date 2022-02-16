/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:47:47 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/16 21:51:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


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
