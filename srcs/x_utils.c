/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:07:04 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/21 18:05:27 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stop_func(int stop, int stop1, int stop2, int stop3)
{
	static int	count = 0;

	if (stop3 != INT_MAX && count++ == 0)
		stop = stop3;
	else if (stop2 != INT_MAX && count++ < 12)
		stop = stop2;
	else if (stop1 != INT_MAX && count++ < 20)
		stop = stop1;
	return (stop);
}

int	stop_func2(int count, int stop, int stop0)
{
	if (count < 1)
		stop0 = stop;
	else if (count < 2)
		stop0 = stop;
	else if (count < 3)
		stop0 = stop;
	return (stop0);
}
