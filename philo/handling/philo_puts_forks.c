/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_puts_forks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:12:14 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/16 16:12:16 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_puts_forks(t_philo *_ph)
{
	if (pthread_mutex_unlock(&_ph->forks) != 0)
		return ;
	if (pthread_mutex_unlock(&_ph->next->forks) != 0)
		return ;
}
