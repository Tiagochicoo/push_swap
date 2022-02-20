/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/20 16:56:26 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack*a, t_stack*b)
{
	t_stack	*temp;

	
}

int main(int argc, char** argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	a = init_a(argc, argv, a);
	if (check_args(argc, argv) && !check_order(a))
	{
		if (argc < 2)
			return (0);
		else if (argc < 7)
			sort_5_or_less(a, b);
		else
			sort_stack(a, b);
	}
	return (0);
}
