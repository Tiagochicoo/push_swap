/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2022/01/25 18:21:47 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compare_args(void*one, void*two)
{
	if (one > two)
		return (0);
	return (1);
}

// void	sort_2_args(t_stack*head)
// {
// 	int	one;
// 	int	two;

// 	one = head->content;
// 	two = head->next->content;
// 	if (one > two)
// 		sa(&head);
// }

// void	sort_3_args(t_stack *a)
// {
// 	void		*first;
// 	void		*second;
// 	void		*third;
// 	t_stack		*temp;

// 	temp = a;
// 	first = a->content;
// 	second = a->next->content;
// 	third = a->next->next->content;
// 	if (first > second && second < third)
// 	{
// 		if (third < first)
// 			sa(&temp);
// 		else
// 			ft_printf("RA\n");
// 	}
// 	else if (first > second && second > third)
// 	{
// 		//sa(a);
// 		ft_printf("SA\n");
// 		ft_printf("RRA\n");
// 		//rra(a);
// 	}
// 	else if (first > second && second < third)
// 		//ra(a);
// 		ft_printf("RA\n");
// 	else if (first < second && second > third)
// 	{
// 		if (third > first)
// 		{
// 			sa(a);
// 			ra(a);
// 		}
// 		else
// 			ft_printf("RRA\n");
// 			//rra();	
// 	}
// }
