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

t_stack	*init_a(int argc, char**argv, t_stack*a)
{
	int		i;
	int		content;
	t_stack	*temp;

	i = 1;
	while (i < argc)
	{
		content = ft_atoi(argv[i]);
		temp = ft_stacknew(content);
		ft_stackadd_back(&a, temp);
		i++;
	}
	return (a);
}
