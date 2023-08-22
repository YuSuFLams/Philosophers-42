/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:06:58 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/16 02:49:55 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_arg(int ac, char **str)
{
	if (ft_atoi(str[1]) < 1 || ft_atoi(str[1]) > 200 || !is_all_digit(str[1]))
		return (ft_error_arg(NBR_PHILO));
	if (ft_atoi(str[2]) < 60 || !is_all_digit(str[2]))
		return (ft_error_arg(TIME_DIE));
	if (ft_atoi(str[3]) < 60 || !is_all_digit(str[3]))
		return (ft_error_arg(TIME_EAT));
	if (ft_atoi(str[4]) < 60 || !is_all_digit(str[4]))
		return (ft_error_arg(TIME_SLEEP));
	if (ac == 6)
		if (ft_atoi(str[5]) < 1 || !is_all_digit(str[5]))
			return (ft_error_arg(NBR_EAT));
	return (0);
}
