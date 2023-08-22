/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:21:16 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/22 11:01:49 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*philo_new_node(t_inf_ph *_ph, int ind)
{
	t_philo	*_phil;

	_phil = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!_phil)
		return (_phil);
	_phil->philo_id = ind;
	_phil->last_eat = get_time();
	if (pthread_mutex_init(&_phil->forks, NULL) != 0)
		return (NULL);
	_phil->numb_eat = 0;
	_phil->_philo = _ph;
	_phil->next = NULL;
	return (_phil);
}

t_philo	*last_philo(t_philo *_ph)
{
	if (!_ph)
		return (_ph);
	while (_ph->next)
		_ph = _ph->next;
	return (_ph);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new_ph)
{
	t_philo	*philo;

	philo = *lst;
	if (!new_ph)
		return ;
	if (!(*lst))
	{
		*lst = new_ph;
		return ;
	}
	philo = last_philo(*lst);
	philo->next = new_ph;
}
