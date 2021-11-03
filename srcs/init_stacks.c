/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:47:47 by tpereira          #+#    #+#             */
/*   Updated: 2021/11/03 09:12:44 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	convert_to_int(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp != NULL)
	{
		temp->content = (int)ft_atoi(temp->content);
		temp = temp->next;
	}	
}