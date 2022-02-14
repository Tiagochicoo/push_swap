/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/14 18:44:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(t_list*list)
{
	if (list)
		ft_lstclear(&list, free);
	ft_putendl_fd("Erro", 2);
	exit(1);
}

int main(int argc, char** argv)
{
	t_list	*a;
	t_list	*b;

	a = init_a(argc, argv);
	b = NULL;
	if (check_args(argc, argv) && !check_order(a))
	{
		if (argc < 2)
			error(a);
		else if (argc < 4)
			small_sort(&a, &b);
		// else if (!check_order(a))
		// 	sort_stack(&a, &b);
	}
	ft_lstclear(&a, free);
	return (0);
}
