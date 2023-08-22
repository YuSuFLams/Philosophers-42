/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:07:12 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/16 02:55:59 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	get_args(t_inf_ph *philo, int ac, char **s)
{
	if (ac > 4)
	{
		philo->nbr_philo = ft_atoi(s[1]);
		philo->time_to_die = ft_atoi(s[2]);
		philo->time_to_eat = ft_atoi(s[3]);
		philo->time_to_sleep = ft_atoi(s[4]);
		philo->time_start = get_time();
		philo->test = true;
		philo->nbr_must_eat = -1;
		if (ac == 6)
			philo->nbr_must_eat = ft_atoi(s[5]);
	}
}
