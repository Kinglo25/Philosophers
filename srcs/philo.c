/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:34:01 by lmajerus          #+#    #+#             */
/*   Updated: 2024/04/23 15:37:13 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_eats(t_phil *phil, t_glob *g)
{
	if (pthread_mutex_lock(&g->forks[phil->l_fork]))
		return (42);
	if (print_status("has taken a fork\n", phil->id, g))
		return (42);
	if (phil->l_fork == phil->r_fork)
		return (pthread_mutex_unlock(&g->forks[phil->l_fork]));
	if (pthread_mutex_lock(&g->forks[phil->r_fork]))
		return (42);
	if (print_status("has taken a fork\n", phil->id, g))
		return (42);
	if (pthread_mutex_lock(&g->check))
		return (42);
	phil->t_last_meal = timestamp();
	if (print_status("is eating\n", phil->id, g))
		return (42);
	phil->nb_ate++;
	if (pthread_mutex_unlock(&g->check))
		return (42);
	ft_sleep(g->t_eat, g);
	if (pthread_mutex_unlock(&g->forks[phil->l_fork]))
		return (42);
	if (pthread_mutex_unlock(&g->forks[phil->r_fork]))
		return (42);
	return (0);
}

static void	*routine(void *arg)
{
	t_phil	*phil;
	t_glob	*g;

	phil = (t_phil *)arg;
	g = phil->g;
	if (phil->id % 2)
		usleep(1500);
	while (simu_ended(g))
	{
		philo_eats(phil, g);
		if (phil->l_fork == phil->r_fork)
			break ;
		print_status("is sleeping\n", phil->id, g);
		ft_sleep(g->t_sleep, g);
		print_status("is thinking\n", phil->id, g);
	}
	return (NULL);
}

static void	check_if_dead_2(t_glob *g, t_phil *p, int i)
{
	while (g->nb_max_eat != -1 && i < g->nb_phil
		&& p[i].nb_ate >= g->nb_max_eat)
		i++;
	pthread_mutex_lock(&g->dead);
	if (i == g->nb_phil)
		g->ate_max = 1;
	pthread_mutex_unlock(&g->dead);
}

static void	check_if_dead(t_glob *g, t_phil *p, int i)
{
	while (!g->ate_max)
	{
		i = 0;
		usleep(1500);
		pthread_mutex_lock(&g->check);
		while (i < g->nb_phil && simu_ended(g))
		{
			if (time_diff(p[i].t_last_meal, timestamp()) >= g->t_die)
			{
				print_status("died\n", i, g);
				pthread_mutex_lock(&g->dead);
				g->died = 1;
				pthread_mutex_unlock(&g->dead);
			}
			i++;
		}
		if (g->died)
			break ;
		check_if_dead_2(g, p, 0);
		pthread_mutex_unlock(&g->check);
	}
	pthread_mutex_unlock(&g->check);
}

int	philo(t_glob *g)
{
	int		i;
	t_phil	*phil;

	i = 0;
	phil = g->phil;
	g->first_timestamp = timestamp();
	while (i < g->nb_phil)
	{
		if (pthread_create(&phil[i].thread_id, NULL, routine, phil + i))
			return (42);
		pthread_mutex_lock(&g->check);
		phil[i].t_last_meal = timestamp();
		pthread_mutex_unlock(&g->check);
		i++;
	}
	check_if_dead(g, g->phil, i);
	i = 0;
	while (i < g->nb_phil)
		if (pthread_join(phil[i++].thread_id, NULL))
			return (42);
	if (mutex_destroy(g))
		return (42);
	return (0);
}
