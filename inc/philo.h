/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:24:36 by lmajerus          #+#    #+#             */
/*   Updated: 2024/04/23 14:55:43 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <fcntl.h>
# include <pthread.h>
# include <string.h>

typedef struct s_phil
{
	int				id;
	int				nb_ate;
	int				l_fork;
	int				r_fork;
	long long		t_last_meal;
	struct s_glob	*g;
	pthread_t		thread_id;
}			t_phil;

typedef struct s_glob
{
	int				nb_phil;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_max_eat;
	int				died;
	int				ate_max;
	long long		first_timestamp;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	writing;
	pthread_mutex_t	check;
	pthread_mutex_t	dead;
	t_phil			phil[200];
}				t_glob;

// init.c

int			init_all(char **av, t_glob *g);

// utils.c

size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
int			time_diff(long long past, long long pres);
void		ft_sleep(int time, t_glob *g);
long long	timestamp(void);
int			error(char *str);
int			print_status(char *str, int id, t_glob *g);
int			mutex_destroy(t_glob *g);
int			simu_ended(t_glob *g);

// philo.c

int			philo(t_glob *g);

#endif
