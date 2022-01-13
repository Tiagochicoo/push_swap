/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/13 22:22:44 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pop_head(t_list**head)
{
	t_list	*temp;

	temp = *head;
	if (head == NULL || *head == NULL)
		return;
	*head = (*head)->next;

	free(temp);
}

t_list	*sort_stack(t_list**a, t_list**b)
{
	int	temp;

	while(a != NULL)
	{
		temp = (*a)->content;
		pop_head(a);
		if (b == NULL || (*b)->content == NULL)
			*b = ft_lstnew(temp);
		else
		{
			while(b != NULL && (*b)->content > temp)
			{
				pa(b, a);
				pop_head(b);
			}
				pa(a, &b);
		}
		check_order(a);
	}
}

int main(int argc, char** argv)
{
	t_list	*a;
	t_list	*b;

	a = init_a(argc, argv);
	b = (t_list*)malloc(sizeof(t_list));
	//convert_to_int(a);
	if (argc < 2)
		write(1, "ERROR: not enough parameters", 28);
	else if (check_args(argc, argv))
		sort_stack(&a, &b);
	 return (0);
}