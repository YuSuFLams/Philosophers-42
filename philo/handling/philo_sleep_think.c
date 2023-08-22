/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep_think.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:12:07 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/16 16:12:09 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_sleep_think(t_philo *_ph)
{
	print_message(_ph, SLEEP);
	sleep_time(_ph->_philo->time_to_sleep);
	print_message(_ph, THINK);
}
