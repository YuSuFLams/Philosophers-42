/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:21:15 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/19 14:59:22 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>

# define INT_X	+2147483647
# define INT_N	-2147483648

# define MEM_ERROR "Memory Allocation Failed."

# define NBR_PHILO "\e[1;33mThe Number Of Philosophers Must Be Greater \
Than 0 And Less Than 200.\033[0m"
# define TIME_DIE "\e[1;33mIt Must Be Time To Die Over 60.\033[0m"
# define TIME_EAT "\e[1;33mEating Time Should Be More Than 60.\033[0m"
# define TIME_SLEEP "\e[1;33mSleep Time Should Be Greater Than 60.\033[0m"
# define NBR_EAT "\e[1;33mTime To Eat Must Be More Than 0.\033[0m"

# define RIGHT_FORKS "\e[1;30mTAKE THE RIGHT FORK 🍴.\033[0m"
# define LEFT_FORKS "\e[1;30mTAKE THE LEFT FORK 🍴.\033[0m"
# define THINK "\e[1;32mTHINKING 🤔💭.\033[0m"
# define SLEEP "\e[1;33mSLEEPING 😴💤.\033[0m"
# define EAT "\e[1;35mEATING 🍽.\033[0m"
# define DIED "\e[1;31mDIED 😱.\033[0m"

typedef struct s_inf_ph
{
	long long			nbr_philo;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	long long			nbr_must_eat;

	long long			time_start;
	int					finish_ate;
	bool				test;

	pthread_mutex_t		p_lock;
	pthread_mutex_t		l_eat;
}	t_inf_ph;

typedef struct s_philo
{
	int				philo_id;
	int				numb_eat;

	pthread_mutex_t	forks;
	pthread_t		ph_thread;

	long long		last_eat;

	struct s_philo	*next;
	struct s_inf_ph	*_philo;
}	t_philo;

//src_libft
int			ft_isdigit(int c);
int			is_all_digit(char *s);
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_lstadd_back(t_philo **lst, t_philo *new_ph);

//check errors philosophers
void		ft_error(void);
int			ft_error_arg(char *s);
void		free_all(t_philo *ph, t_inf_ph *philo);
int			check_arg(int ac, char **str);

//routines philosophers
void		*routin_ph(void *arg);
void		check_fin(t_philo *ph);
void		check_die(t_philo *ph);
void		philo_eating(t_philo *_ph);
void		check_eat_fin(t_philo *ph);
void		philo_take_forks(t_philo *_ph);
void		philo_puts_forks(t_philo *_ph);
void		philo_sleep_think(t_philo *_ph);

//times philosophers
long long	get_time(void);
long long	current_time(t_philo *ph);
void		sleep_time(long long time);

//utils philosophers
t_philo		*last_philo(t_philo *_ph);
t_philo		*philo_add(t_inf_ph *inf_ph);
void		create_threads(t_philo *philo);
void		print_message(t_philo *_ph, char *s);
t_philo		*philo_new_node(t_inf_ph *_ph, int ind);
void		get_args(t_inf_ph *philo, int ac, char **s);

#endif