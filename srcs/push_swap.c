/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2021/10/25 13:08:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char** argv)
{
	int*	a;
	// char*	b;

	if (argc < 2)
		write(1, "ERROR: not enough parameters", 28);
	else
	{
		int i = 1;
		while (argv[i])
		{
			write(1, &argv[i][0], ft_strlen(&argv[i][0]));
			write(1, " ", 1);
			check_arg(argc, argv[i]);
			i++;
		}
			write(1, "\n", 1);
	}
	return (0);
}