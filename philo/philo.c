/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:35:44 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/22 17:35:49 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char **str)
{
	t_inf_ph	*philo;
	t_philo		*ph;

	if (ac < 5 || ac > 6)
		return (ft_error(), 1);
	if (check_arg(ac, str))
		return (1);
	philo = malloc(sizeof(t_inf_ph));
	if (!philo)
		return (ft_error_arg(MEM_ERROR));
	get_args(philo, ac, str);
	ph = philo_add(philo);
	if (!ph)
	{
		free(philo);
		return (ft_error_arg(MEM_ERROR));
	}
	create_threads(ph);
	check_fin(ph);
	free_all(ph, philo);
	return (0);
}
