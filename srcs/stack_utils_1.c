/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:05:11 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/14 18:54:35 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack*stack, void*content)
{
	t_list	*head;

	head = ft_lstnew(content);
	head->next = stack->head;
	stack->head = head;
	stack->size++;
}

void	*pop(t_stack*stack)
{
	t_list	*head;
	void	*content;

	if (!stack->head)
		return (NULL);
	head = stack->head;
	content = head->content;
	stack->head = head->next;
	stack->size--;
	free(head);
	return (content);
}
