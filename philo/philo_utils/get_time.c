/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:29:23 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/16 16:03:32 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	current_time(t_philo *ph)
{
	return (get_time() - ph->_philo->time_start);
}

void	sleep_time(long long time)
{
	long long	start_time;

	start_time = get_time();
	while (get_time() < time + start_time)
		usleep(100);
}
