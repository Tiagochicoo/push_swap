/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2021/11/08 21:39:59 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_args(t_list *head)
{
	t_list *temp = head;

	while (temp != NULL)
	{
		printf("%d\n", (int)temp->content);
		temp = temp->next;
	}
}

int main(int argc, char** argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		write(1, "ERROR: not enough parameters", 28);
	else if (argc >= 2)
	{
		if (check_args(argc, argv) == 1)
		{
			a = init_a(argc, argv);
			convert_to_int(a);
			if (check_order(a) == 0)
			{
				b = NULL;
				print_args(a);
			}
		}
	}
	return (0);
}