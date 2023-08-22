/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_ph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:12:53 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/16 16:12:59 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routin_ph(void *arg)
{
	t_philo	*_ph;

	_ph = (t_philo *)arg;
	while (1337)
	{
		philo_take_forks(_ph);
		philo_eating(_ph);
		philo_puts_forks(_ph);
		philo_sleep_think(_ph);
	}
	return (NULL);
}
