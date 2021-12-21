/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_3_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2021/12/21 19:30:58 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		compare_args(void*one, void*two)
{
	if (one > two)
		return (0);
	return (1);
}

void	order_3_args(t_list *a)
{
	void		*first;
	void		*second;
	void		*third;
	t_list		*temp;

	temp = a;	
	first = a->content;
	second = a->next->content;
	third = a->next->next->content;
	if (first > second && second < third)
	{
		if (third > first)
		{
			ft_printf("case 1");
			sa(temp);
			ft_printf("case 1");
		}
		else
		ft_printf("RA\n");
	}		
	else if (first > second && second > third)
	{
		//sa(a);
		ft_printf("SA\n");
		ft_printf("RRA\n");
		//rra(a);
	}
	else if (first > second && second < third)
		//ra(a);
		ft_printf("RA\n");
	else if (first < second && second > third)
	{
		if (third > first)
		{
			ft_printf("SA\n");
			//sa(a);
			ft_printf("RA\n");
			//ra(a);
		}
		else
			ft_printf("RRA\n");
			//rra();	
	}
}