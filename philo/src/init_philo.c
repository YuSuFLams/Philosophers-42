/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:07:22 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/22 12:04:15 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*philo_add(t_inf_ph *inf_ph)
{
	t_philo		*new_ph;
	int			i;

	new_ph = NULL;
	i = 1;
	if (pthread_mutex_init(&inf_ph->p_lock, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&inf_ph->l_eat, NULL) != 0)
		return (NULL);
	while (i <= inf_ph->nbr_philo)
		ft_lstadd_back(&new_ph, philo_new_node(inf_ph, i++));
	last_philo(new_ph)->next = new_ph;
	return (new_ph);
}

void	create_threads(t_philo *philo)
{
	int	i;

	i = 1;
	philo->_philo->finish_ate = 0;
	while (i++ <= philo->_philo->nbr_philo)
	{
		if (pthread_create(&philo->ph_thread, NULL, &routin_ph, philo) != 0)
		{
			printf("Thread creation failed");
			return ;
		}
		if (pthread_detach(philo->ph_thread) != 0)
			return ;
		usleep(300);
		philo = philo->next;
	}
}
