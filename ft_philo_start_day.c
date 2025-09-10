#include "philo.h"


void	ft_sleep(t_args *st, int id)
{
	if (st->someone_died == 0)
		return ;
	pthread_mutex_lock(&st->time_t);
	ft_get_my_time(&st->t_start);
	usleep(1000 * st->time_to_sleep);
	ft_get_my_time(&st->t_end);
	st->tt = (st->t_end.tv_sec - st->t_start.tv_sec) * 1000
             + (st->t_end.tv_usec - st->t_start.tv_usec) / 1000;
	st->time += st->tt;
	pthread_mutex_lock(&st->print_mutex);
	printf("%ld %d is sleeping\n",st->time, id);
	pthread_mutex_unlock(&st->print_mutex);
	pthread_mutex_unlock(&st->time_t);
}

void	ft_eat(t_args *st, int left, int rigth, int id)
{
	if (st->someone_died == 0)
		return ;
	pthread_mutex_lock(&st->time_t);
	ft_get_my_time(&st->t_start);
	pthread_mutex_lock(&st->forks[left]);
	pthread_mutex_lock(&st->forks[rigth]);
	//printf("%d is eating fork left  -> %d and rigth -> %d\n", id, left,rigth);
	usleep(1000 * st->time_to_eat);
	ft_get_my_time(&st->t_end);
	st->tt = (st->t_end.tv_sec - st->t_start.tv_sec) * 1000
             + (st->t_end.tv_usec - st->t_start.tv_usec) / 1000;
	st->time += st->tt;
	pthread_mutex_lock(&st->print_mutex);
	printf("%ld %d has taken a fork\n", st->time, id);
	printf("%ld %d has taken a fork\n", st->time, id);
	printf("%ld %d is eating\n", st->time, id);
	pthread_mutex_unlock(&st->print_mutex);
	pthread_mutex_unlock(&st->forks[left]);
	pthread_mutex_unlock(&st->forks[rigth]);
	pthread_mutex_unlock(&st->time_t);
}

int	ft_get_fork(t_philo *philo, int id)
{
	if (id % 2 != 0)
	{

		ft_eat(philo->st, philo->st->philo[id].left_fork,
			philo->st->philo[id].right_fork, id);
	}
	else
	{
		usleep(10);
		ft_eat(philo->st, philo->st->philo[id].left_fork,
			philo->st->philo[id].right_fork, id);
	}
	return (0);
}
