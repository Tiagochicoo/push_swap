/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:27:15 by tpereira          #+#    #+#             */
/*   Updated: 2022/02/16 17:27:24 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpos(t_list *list, unsigned int num)
{
	unsigned int	i;

	i = 0;
	while (i++ < num)
	{
		if (!list)
			return (list);
		list = list->next;
	}
	return (list);
}
