/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:32:44 by ahapetro          #+#    #+#             */
/*   Updated: 2025/09/22 19:32:44 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_and_end(t_args *st, int c)
{
	int	i;

	i = 0;
	if (c == 1)
	{
		while (i < st->num_philos)
		{
			pthread_mutex_destroy(&st->forks[i]);
			i++;
		}
		pthread_mutex_destroy(&st->print_mutex);
		pthread_mutex_destroy(&st->deat);
		pthread_mutex_destroy(&st->time_t);
		pthread_mutex_destroy(&st->meal_m);
		free(st->forks);
		st->forks = NULL;
		if (st->philo)
		{
			free(st->philo);
			st->philo = NULL;
		}
	}
	free(st);
}
