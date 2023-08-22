/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:11:30 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/18 17:25:09 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_die(t_philo *ph)
{
	if (ph->_philo->time_to_die + ph->last_eat < get_time())
	{
		if (pthread_mutex_lock(&ph->_philo->p_lock) != 0)
			return ;
		printf("\e[0;94m%lld  THE [%d] PHILOSOPHER IS %s\n\033[0m", \
		current_time(ph), ph->philo_id, DIED);
		ph->_philo->test = false;
		return ;
	}
}

void	check_eat_fin(t_philo *ph)
{
	if (ph->_philo->nbr_must_eat > 0)
	{
		if (ph->_philo->finish_ate == ph->_philo->nbr_philo)
		{
			if (pthread_mutex_lock(&ph->_philo->p_lock) != 0)
				return ;
			ph->_philo->test = false;
		}
		return ;
	}
}

void	check_fin(t_philo *ph)
{
	while (1337)
	{
		if (pthread_mutex_lock(&ph->_philo->l_eat) != 0)
			return ;
		check_eat_fin(ph);
		check_die(ph);
		if (!ph->_philo->test)
			break ;
		if (pthread_mutex_unlock(&ph->_philo->l_eat) != 0)
			return ;
		ph = ph->next;
	}
}
