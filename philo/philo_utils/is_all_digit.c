/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:30:21 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/16 02:49:47 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_all_digit(char *s)
{
	int	i;

	i = 0;
	if (*s == '+')
		i++;
	while (*(s + i))
	{
		if (!ft_isdigit(*(s + i)))
			return (0);
		i++;
	}
	return (1);
}
