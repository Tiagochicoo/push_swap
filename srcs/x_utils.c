/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:07:04 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/21 18:39:20 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stop	*init_stop(t_stop*stop)
{
	stop = (t_stop*)malloc(sizeof(t_stop));
	stop->stop = INT_MAX;
	stop->stop1 = INT_MAX;
	stop->stop2 = INT_MAX;
	stop->stop3 = INT_MAX;
	return (stop);
}

t_stop	*stop_func(t_stop*stop)
{
	static int	count = 0;

	if (stop->stop3 != INT_MAX && count++ == 0)
		stop->stop = stop->stop3;
	else if (stop->stop2 != INT_MAX && count++ < 12)
		stop->stop = stop->stop2;
	else if (stop->stop1 != INT_MAX && count++ < 20)
		stop->stop = stop->stop1;
	return (stop);
}

t_stop	*stop_func2(int count, t_stop*stop)
{
	if (count < 1)
		stop->stop1 = stop->stop;
	else if (count < 2)
		stop->stop2 = stop->stop;
	else if (count < 3)
		stop->stop3 = stop->stop;
	return (stop);
}
