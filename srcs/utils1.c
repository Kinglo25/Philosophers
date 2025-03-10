/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:51:56 by lmajerus          #+#    #+#             */
/*   Updated: 2024/05/16 14:15:12 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	ft_sleep(int time, t_glob *g)
{
	long long	t;

	t = timestamp();
	(void)g;
	while (time_diff(t, timestamp()) <= time)
		usleep(2 * g->nb_phil);
}

int	error(char *str)
{
	write(2, "Error: ", 7);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (42);
}

int	mutex_destroy(t_glob *g)
{
	int	i;

	i = 0;
	while (i < g->nb_phil)
	{
		if (pthread_mutex_destroy(&g->forks[i]))
			return (42);
		i++;
	}
	if (pthread_mutex_destroy(&g->check))
		return (42);
	if (pthread_mutex_destroy(&g->writing))
		return (42);
	return (0);
}

int	simu_ended(t_glob *g)
{
	int	ret;

	pthread_mutex_lock(&g->dead);
	ret = !g->died && !g->ate_max;
	pthread_mutex_unlock(&g->dead);
	return (ret);
}
