/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:07:04 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/22 08:11:01 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stop(t_stop*stop)
{
	stop->stop = INT_MAX;
	stop->stop1 = INT_MAX;
	stop->stop2 = INT_MAX;
	stop->stop3 = INT_MAX;
	stop->count = 0;
	stop->count1 = 0;
}

t_stop	*stop_func(t_stop*stop)
{
	if (stop->stop3 != INT_MAX && stop->count1 == 0)
	{
		stop->stop = stop->stop3;
		stop->count1++;
	}
	else if (stop->stop2 != INT_MAX && stop->count1 < 6)
	{
		stop->stop = stop->stop2;
		stop->count1++;
	}
	else if (stop->stop1 != INT_MAX && stop->count1 < 20)
	{
		stop->stop = stop->stop1;
		stop->count1++;
	}
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

t_stop	*stop_func3(int count, t_stop*stop, int content)
{
	if (count == 0)
		stop->stop1 = content;
	else if (count == 1)
		stop->stop2 = content;
	else if (count == 2)
		stop->stop3 = content;
	else if (count >= 3)
		stop->stop2 = content;
	return (stop);
}

t_stop	*stop_func4(int count, t_stop*stop, int content)
{
	if (count == 0)
		stop->stop1 = content;
	else if (count == 1)
		stop->stop2 = content;
	else if (count == 2)
		stop->stop3 = content;
	else if (count >= 3)
		stop->stop2 = content;
	return (stop);
}
