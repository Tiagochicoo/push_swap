/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/16 18:44:57 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(t_list*list)
{
	if (list)
		ft_lstclear(&list, free);
	ft_putendl_fd("Error", 2);
	exit(1);
}

int main(int argc, char** argv)
{
	t_stack	a;
	t_stack	b;

	a = (t_stack){init_a(argc, argv), argc - 1};
	b = (t_stack){NULL, 0};
	if (check_args(argc, argv) && !check_order(a.head))
	{
		if (argc < 2)
			error(a.head);
		else if (argc <= 4)
			small_sort(&a, &b);
		else if (argc <= 6)
			medium_sort(&a, &b);
	}
	//ft_lstclear(&a.head, free);
	return (0);
}
