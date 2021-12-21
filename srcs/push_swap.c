/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2021/12/21 16:28:45 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	order_loop(int argc, char**argv)
{
	t_list	*a;
	t_list	*b;

	if (check_args(argc, argv))
	{
		a = init_a(argc, argv);
		convert_to_int(a);
		if (check_order(a))
		{
			b = NULL;
			ft_printf("Ordered!\n");
		}
		else
			ft_printf("Put some order on this!\n");
	}
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
	if (argc <= 2)
		write(1, "ERROR: not enough parameters", 28);
	else if (argc > 2)
	{
		order_loop(argc, argv);
	}
	return (0);
}
