/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:18:14 by tpereira          #+#    #+#             */
/*   Updated: 2021/10/25 17:53:23 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_dup(char* arg)
{
	//check later
}

int	check_int(char* arg)
{
	int num;

	num = ft_atoi(arg);
	if (arg[0] == '-' && arg[1] == '1' && arg[2] == '\0')
		return (1);
	if (num != -1)
		return (1);
	else
		return (0);
	return (0);
}

int	check_arg(int argc, char* arg)
{	
	if (ft_isnumber(arg) == 0 || check_int(arg) == 0)
		return (0);
	else
		return (1);
	return (0);
}
//check for errors
// some arguments aren’t integers, some arguments are
//bigger/smaller than an integer, and/or there are duplicates.