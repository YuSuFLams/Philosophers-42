/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:10:55 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/22 11:01:05 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eating(t_philo *_ph)
{
	print_message(_ph, EAT);
	if (pthread_mutex_lock(&_ph->_philo->l_eat) != 0)
		return ;
	_ph->last_eat = get_time();
	_ph->numb_eat++;
	if (_ph->numb_eat == _ph->_philo->nbr_must_eat)
		_ph->_philo->finish_ate++;
	if (pthread_mutex_unlock(&_ph->_philo->l_eat) != 0)
		return ;
	sleep_time(_ph->_philo->time_to_eat);
}
