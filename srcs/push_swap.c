/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:50:42 by tpereira          #+#    #+#             */
/*   Updated: 2021/10/26 19:52:56 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_dup(int argc, char** argv)
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

// void push(t_list * head, int val) {
//     t_list * current = head;
//     while (current->next != NULL) {
//         current = current->next;
//     }

//     /* now we can add a new variable */
//     current->next = (t_list *) malloc(sizeof(t_list));
//     current->next->content = val;
//     current->next->next = NULL;
// }

void	new_stacks(int argc, char** argv)
{
	t_list	a;
	// t_list	b;
	// int		i;

	// i = 2;
	a = *ft_lstnew(argv[1]);
	// while (argv[i])
	// {
	// 	ft_lstadd_front();
	// 	push(a, ft_atoi(argv[i]));
	// 	i++;
	// }
	// b = *ft_lstnew("");

	write(1, (char* )a.content, ft_strlen((char *)a.content));
}

int	check_args(int argc, char** argv)
{
	int i = 1;
	while (i < argc)
	{
		// write(1, &argv[i][0], ft_strlen(&argv[i][0]));
		// write(1, " ", 1);
		if (check_dup(argc, argv) == 0)
		{
			write(1, "Duplicate\n", 10);
			return (0);
		}
		if (check_arg(argc, argv[i]) == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
		//write(1, "\n", 1);
}

int main(int argc, char** argv)
{
	if (argc < 2)
		write(1, "ERROR: not enough parameters", 28);
	else if (argc >= 2)
	{
		if (check_args(argc, argv) != 1);
		{
			new_stacks(argc, argv);
		}
	}
	return (0);
}