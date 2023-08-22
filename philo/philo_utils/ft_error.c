/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:00:12 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/22 11:01:32 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_error(void)
{
	printf("\033[91mError : Your Arguments Must Be Valid\n\033[0m");
	printf("\033[95m/Usage : ./philo \033[93m<number_of_philosophers> ");
	printf("\033[93m<time_to_die> <time_to_eat> <time_to_sleep> ");
	printf("\033[93m|| [number_of_times_each_philosopher_must_eat]\n");
}

int	ft_error_arg(char *s)
{
	printf("\033[94mError: %s\n\033[0m", s);
	return (1);
}

void	free_all(t_philo *ph, t_inf_ph *philo)
{
	if (pthread_mutex_destroy(&ph->_philo->l_eat) != 0)
		return ;
	if (pthread_mutex_destroy(&ph->forks) != 0)
		return ;
	if (pthread_mutex_destroy(&ph->_philo->p_lock) != 0)
		return ;
	free(philo);
	free(ph);
}
