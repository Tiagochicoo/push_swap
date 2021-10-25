/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:18:14 by tpereira          #+#    #+#             */
/*   Updated: 2021/10/25 13:07:45 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_arg(int argc, char* arg)
{
	int	is_number;

	is_number = ft_isnumber(arg);
	if (is_number > 0)
		write(1, "number\n", 7);
	else
		write(1, "Error\n", 6);
}
//check for errors
// some arguments aren’t integers, some arguments are
//bigger/smaller than an integer, and/or there are duplicates.