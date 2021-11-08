/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:18:14 by tpereira          #+#    #+#             */
/*   Updated: 2021/11/08 20:24:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     check_order(t_list *a)
{
	t_list	*temp;

	temp = a;
	if (a == NULL)
		return (1);
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
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

int	check_arg(char* arg)
{
	if (ft_isnumber(arg) == 0 || check_int(arg) == 0)
		return (0);
	else
		return (1);
	return (0);
}

int	check_dup(char** argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 2;
		while (argv[j])
		{
			if (i != j && ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char** argv)
{
	int i = 1;
	while (i < argc)
	{
		int	flag;

		flag = 0;
		flag += check_dup(argv);
		flag += check_arg(argv[i]);
		if (flag < 2)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
//check for errors
// some arguments aren’t integers, some arguments are
//bigger/smaller than an integer, and/or there are duplicates.

//check if already ordered!!