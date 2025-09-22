#include "philo.h"

void	ft_think(t_args *st, int id)
{
	if (ft_c_d(&st->deat, st->someone_died, &st->philo[id]) == 1)
		return ;
	ft_print_all(st, ft_timestamp(&st->start), id, 4);
	if (ft_c_d(&st->deat, st->someone_died, &st->philo[id]) == 1)
		return ;
}

void	ft_sleep(t_args *st, int id)
{
	if (ft_c_d(&st->deat, st->someone_died, &st->philo[id]) == 1)
		return ;
	ft_print_all(st, ft_timestamp(&st->start), id, 3);
	ft_simple_sleep(st->time_to_sleep, st);
	ft_time(st, id);
	if (ft_c_d(&st->deat, st->someone_died, &st->philo[id]) == 1)
		return ;
}

void	ft_eat(t_args *st, int left, int rigth, int id)
{
	if (ft_c_d(&st->deat, st->someone_died, &st->philo[id]) == 1)
		return ;
	pthread_mutex_lock(&st->forks[left]);
	ft_print_all(st, ft_timestamp(&st->start), id, 1);
	if (st->num_philos == 1 || st->time_to_die < st->time_to_eat
		|| get_someone_died(st) != -1)
	{
		ft_iiiii(st, left);
		return ;
	}
	if (ft_chek_think(st) == 1)
		return ;
	pthread_mutex_lock(&st->forks[rigth]);
	ft_print_all(st, ft_timestamp(&st->start), id, 1);
	ft_time(st, id);
	ft_print_all(st, ft_timestamp(&st->start), id, 2);
	ft_update(st, id);
	ft_check_death(st, id);
	ft_simple_sleep(st->time_to_eat, st);
	if (get_someone_died(st) != -1)
	{
		ft_unlock(&st->forks[left], &st->forks[rigth]);
		return ;
	}
	ft_count(st, id, left, rigth);
}

int	ft_get_fork(t_philo *philo, int id)
{
	if (ft_c_d(&philo->st->deat, philo->st->someone_died, philo) == 1)
		return (3);
	if (id % 2 != 0)
		usleep(100);
	if (id % 2 != 0)
	{
		ft_eat(philo->st, philo->st->philo[id].left_fork,
			philo->st->philo[id].right_fork, id);
	}
	else
	{
		ft_eat(philo->st, philo->st->philo[id].right_fork,
			philo->st->philo[id].left_fork, id);
	}
	return (0);
}

void	*my_thread_function(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (ft_c_d(&philo->st->deat, philo->st->someone_died, philo) == 1)
		return (NULL);
	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
	{
		if (ft_c_d(&philo->st->deat, philo->st->someone_died, philo) == 1)
			return (NULL);
		ft_get_fork(philo, philo->id);
		ft_sleep(philo->st, philo->id);
		ft_think(philo->st, philo->id);
	}
	return (NULL);
}
