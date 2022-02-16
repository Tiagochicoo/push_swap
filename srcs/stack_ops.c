/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:52:37 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/16 16:55:52 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack*stack)
{
	void	*content;
	
	content = pop(stack);
	if (content)
		shift(stack, content);
}

void	rev_rotate(t_stack*stack)
{
	void	*content;

	content = unshift(stack);
	if (content)
		push(stack, content);
}

void	swap(t_stack*stack)
{
	void	*one;
	void	*two;

	if (stack->size < 2)
		return ;
	one = pop(stack);
	two = pop(stack);
	push(stack, one);
	push(stack, two);
}

void	shift(t_stack*stack, void*content)
{
	t_list	*last;

	last = ft_lstlast(stack->head);
	last->next = ft_lstnew(content);
	stack->size++;
}

void	*unshift(t_stack*stack)
{
	t_list	*last;
	t_list	*before;
	void	*content;

	if(!stack->head)
		return (NULL);
	last = ft_lstlast(stack->head);
	content = last->content;
	if (stack->size > 1)
	{
		before = ft_lstpos();
	}
}