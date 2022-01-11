/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/11 18:41:38 by tpereira         ###   ########.fr       */
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

	a = init_a(argc, argv);
	b = NULL;
	convert_to_int(a);
	if (argc < 2)
		write(1, "ERROR: not enough parameters", 28);
	if (check_args(argc, argv))
	{
		if (argc == 3)
			sort_2_args(a);
		if (argc == 4)
			sort_3_args(a);
	}
	else
	// else if (argc > 4)
	// {
	// 	insertion_sort();
	// 	if (check_args(argc, argv))
	// 	{
	// 		if (check_order(a))
	// 			print_args(a);
	// 		else
	// 			sort_args(a, b);
	// 	}
	// }
	 return (0);
}