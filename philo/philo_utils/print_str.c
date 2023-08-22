/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:18:10 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/22 11:01:20 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_message(t_philo *_ph, char *s)
{
	if (pthread_mutex_lock(&_ph->_philo->p_lock) != 0)
		return ;
	printf("\e[0;94m%lld  THE [%d] PHILOSOPHER IS %s\n\033[0m", \
	current_time(_ph), _ph->philo_id, s);
	if (_ph->_philo->test)
		if (pthread_mutex_unlock(&_ph->_philo->p_lock) != 0)
			return ;
}
