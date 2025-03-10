/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:26:56 by lmajerus          #+#    #+#             */
/*   Updated: 2022/02/01 20:18:27 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_glob	g;

	if (ac != 5 && ac != 6)
		return (error("Invalid # of arg"));
	if (init_all(av, &g))
		return (error("Parsing or init issue") && !mutex_destroy(&g));
	if (philo(&g))
		return (error("Couldn't create threads") && !mutex_destroy(&g));
	return (0);
}
