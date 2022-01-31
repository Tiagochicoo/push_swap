/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:52:37 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/31 16:27:38 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*new_list;

	new_list = (t_stack *)malloc(sizeof(t_stack));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		if (last != NULL)
			last->next = new;
	}
}

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*temp;

	if (lst != NULL)
		temp = lst;
	else
		return (NULL);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
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
