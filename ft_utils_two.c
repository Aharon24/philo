/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:32:52 by ahapetro          #+#    #+#             */
/*   Updated: 2025/09/22 19:32:53 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_chek_think(t_args *st)
{
	return (get_someone_died(st) != -1);
}

int	chek_eat_count(t_args *st)
{
	int	i;

	if (st->must_eat == -1)
		return (0);
	pthread_mutex_lock(&st->meal_m);
	i = 0;
	while (i < st->num_philos)
	{
		if (st->philo[i].eat_count != 0)
		{
			pthread_mutex_unlock(&st->meal_m);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&st->meal_m);
	set_someone_died(st, 2);
	return (1);
}

void	ft_iiiii(t_args *st, int left)
{
	pthread_mutex_unlock(&st->forks[left]);
	set_someone_died(st, 1);
	pthread_mutex_lock(&st->print_mutex);
	usleep(st->time_to_die);
	pthread_mutex_unlock(&st->print_mutex);
}

void	ft_count(t_args *st, int id, int left, int rigth)
{
	pthread_mutex_lock(&st->meal_m);
	if (st->philo[id].eat_count > 0)
		st->philo[id].eat_count--;
	pthread_mutex_unlock(&st->meal_m);
	ft_unlock(&st->forks[left], &st->forks[rigth]);
}

void	ft_monitoring_two(t_args *st, int i)
{
	pthread_mutex_lock(&st->print_mutex);
	ft_daid(&st->deat, i + 1, ft_timestamp(&st->start), st);
	st->free = 1;
	pthread_mutex_unlock(&st->print_mutex);
}
