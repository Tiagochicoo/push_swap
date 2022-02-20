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
