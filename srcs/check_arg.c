/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:18:14 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/22 08:09:08 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_order(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	if (a == NULL)
		return (0);
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_int(char**argv)
{
	int		i;
	int		num;
	char	*str;

	i = 1;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		str = ft_itoa(num);
		if (ft_strcmp(argv[i], str) > 0)
		{
			free(str);
			return (0);
		}
		i++;
		free(str);
	}
	return (1);
}

int	check_arg(char**argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isnumber(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(char**argv)
{
	int	i;
	int	j;
	int	num;
	int	num1;

	i = 1;
	while (argv[i])
	{
		j = 2;
		num = ft_atoi(argv[i]);
		while (argv[j])
		{
			num1 = ft_atoi(argv[j]);
			if (i != j && num == num1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(char**argv)
{
	int	flag;

	flag = 0;
	flag += check_dup(argv);
	flag += check_arg(argv);
	flag += check_int(argv);
	if (flag < 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
