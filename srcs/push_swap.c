/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2021/10/26 15:50:10 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_dup(int argc, char** argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (argv[i])
	{
		j = 2;
		while (argv[j])
		{
			int test = ft_strcmp(argv[i], argv[j]);
			if (i != j && ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	new_stacks(int argc, char** argv)
{
	write(1, "\n",1);
}

int	check_args(int argc, char** argv)
{
	int i = 1;
	while (i < argc)
	{
		// write(1, &argv[i][0], ft_strlen(&argv[i][0]));
		// write(1, " ", 1);
		if (check_dup(argc, argv) == 0)
			return write(1, "Duplicate\n", 10);
		if (check_arg(argc, argv[i]) == 0)
			return write(1, "Error\n", 6);
		i++;
	}
		//write(1, "\n", 1);
}

int main(int argc, char** argv)
{
	if (argc < 2)
		write(1, "ERROR: not enough parameters", 28);
	else if (argc >= 2)
	{
		check_args(argc, argv);
		//new_stacks(argc, argv);
	}
	return (0);
}