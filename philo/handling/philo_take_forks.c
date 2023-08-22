/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_take_forks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:12:28 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/16 16:12:29 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_take_forks(t_philo *_ph)
{
	if (pthread_mutex_lock(&_ph->forks) != 0)
		return ;
	print_message(_ph, RIGHT_FORKS);
	if (pthread_mutex_lock(&_ph->next->forks) != 0)
		return ;
	print_message(_ph, LEFT_FORKS);
}
