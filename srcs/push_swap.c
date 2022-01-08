/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/08 11:56:06 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	order_loop(int argc, char**argv, t_list *a, t_list *b)
{
	while (!check_order(a) || b != NULL)
	{
		if (stack_size(a) == 3)
			order_3_args(a);
		else
			ft_printf("Not ordered!!!\n");
			return;
	}
	ft_printf("Ordered!\n");
}

void	print_args(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", (int)temp->content);
		temp = temp->next;
	}
}

int	main(int argc, char**argv)
{
	t_list	*a;
	t_list	*b;
	
	if (argc <= 2)
		write(1, "ERROR: not enough parameters", 28);
	else if (argc > 2)
	{
		if (check_args(argc, argv))
		{
			a = init_a(argc, argv);
			b = NULL;
			convert_to_int(a);
			order_loop(argc, argv, a, b);
		}
	}
	return (0);
}
