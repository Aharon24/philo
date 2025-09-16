#include "philo.h"

void ft_think(t_args *st, int id)
{
	if (ft_c_d(&st->deat, st->someone_died) == 1)
		return ;
    pthread_mutex_lock(&st->print_mutex);
    printf("%ld %d is thinking\n",st->time, id + 1);
    pthread_mutex_unlock(&st->print_mutex);
}

void	ft_sleep(t_args *st, int id)
{
	if (ft_c_d(&st->deat, st->someone_died) == 1)
		return ;
	ft_print_all(st,st->time, id, 3);
	usleep(1000 * st->time_to_sleep);
	ft_time(st,id);
	if (ft_c_d(&st->deat,st->someone_died) == 1)
		return ;
}

void	ft_eat(t_args *st, int left, int rigth, int id)
{
	if (ft_c_d(&st->deat, st->someone_died) == 1)
		return ;
	pthread_mutex_lock(&st->forks[left]);
	ft_print_all(st,st->time, id, 1);
	pthread_mutex_lock(&st->forks[rigth]);
	ft_print_all(st, st->time, id, 1);
	if (st->num_philos == 1 || st->time_to_die < st->time_to_eat)
	{
		usleep(st->time_to_die * 1000);
		st->someone_died = 1;
		pthread_mutex_unlock(&st->forks[left]);
		pthread_mutex_unlock(&st->forks[rigth]);
		return ;
	}
	ft_time(st, id);
	ft_print_all(st, st->time, id, 2);
	ft_update(st, id);
	ft_check_death(st,id);
	usleep(1000 * st->time_to_eat);
	pthread_mutex_lock(&st->deat);
	if (st->someone_died != -1)
	{
		ft_unlock(&st->forks[left],&st->forks[rigth],&st->deat);
		return ;
	}
	ft_unlock(&st->forks[left],&st->forks[rigth],&st->deat);
}

int	ft_get_fork(t_philo *philo, int id)
{
	if (ft_c_d(&philo->st->deat, philo->st->someone_died) == 1)
		return (3);
	if (id % 2 != 0)
	{
		ft_eat(philo->st, philo->st->philo[id].left_fork,
			philo->st->philo[id].right_fork, id);
	}
	else
	{
		usleep(10);
		ft_eat(philo->st, philo->st->philo[id].right_fork,
			philo->st->philo[id].left_fork, id);
	}
	return (0);
}

void	*my_thread_function(void *arg)
{
	t_philo	*philo;
	philo = (t_philo *)arg;
	if (ft_c_d(&philo->st->deat, philo->st->someone_died) == 1)
		return (NULL);
	if (philo->id % 2 == 0)
        // usleep(10);
	while (1)
	{
		if (ft_c_d(&philo->st->deat, philo->st->someone_died) == 1)
			return (NULL);
		ft_get_fork(philo, philo->id);
		ft_sleep(philo->st, philo->id);
		ft_think(philo->st,philo->id);
	}
	return (NULL);
}
