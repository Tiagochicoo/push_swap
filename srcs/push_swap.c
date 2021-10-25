/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2021/10/25 20:03:07 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char** argv)
{
	int*	a;
	int		is_valid;
	// char*	b;

	if (argc < 2)
		write(1, "ERROR: not enough parameters", 28);
	else if (argc >= 2)
	{
		int i = 1;
		while (i < argc)
		{
			write(1, &argv[i][0], ft_strlen(&argv[i][0]));
			write(1, " ", 1);
			if (check_arg(argc, argv[i]) == 0)
				return write(1, "Error\n", 6);
			i++;
		}
			write(1, "\n", 1);
	}
	return (0);
}