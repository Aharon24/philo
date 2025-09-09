#include "philo.h"


void	ft_sleep(t_args *st, int id)
{
	if (st->someone_died == 0)
		return ;
	ft_get_my_time(&st->t_start);
	pthread_mutex_lock(&st->print_mutex);
	printf("%d is sleeping\n",id);
	pthread_mutex_unlock(&st->print_mutex);
	usleep(1000 * st->time_to_sleep);
	ft_get_my_time(&st->t_end);
	pthread_mutex_lock(&st->time_t);
	st->time = (st->t_end.tv_sec - st->t_start.tv_sec) * 1000
             + (st->t_end.tv_usec - st->t_start.tv_usec) / 1000;
	pthread_mutex_unlock(&st->time_t);
	if ((st->time) > (st->time_to_sleep))
	{
		pthread_mutex_lock(&st->print_mutex);
		printf("Time %ld\n",st->time);
		pthread_mutex_unlock(&st->print_mutex);
		st->someone_died = 0;
	}
	
}

void	ft_eat(t_args *st, int left, int rigth, int id)
{
	if (st->someone_died == 0)
		return ;
	ft_get_my_time(&st->t_start);
	pthread_mutex_lock(&st->forks[left]);
	pthread_mutex_lock(&st->forks[rigth]);
	pthread_mutex_lock(&st->print_mutex);
	printf("%d is eating\n", id);
	pthread_mutex_unlock(&st->print_mutex);

	usleep(1000 * st->time_to_eat);
	pthread_mutex_unlock(&st->forks[left]);
	pthread_mutex_unlock(&st->forks[rigth]);
	ft_get_my_time(&st->t_end);
	pthread_mutex_lock(&st->time_t);
	st->time = (st->t_end.tv_sec - st->t_start.tv_sec) * 1000
             + (st->t_end.tv_usec - st->t_start.tv_usec) / 1000;
	pthread_mutex_unlock(&st->time_t);
	if ((st->time) > (st->time_to_eat))
	{
		pthread_mutex_lock(&st->print_mutex);
		printf("Time %ld\n",st->time);
		pthread_mutex_unlock(&st->print_mutex);
		st->someone_died = 0;
	}
}

void	ft_get_fork(t_philo *philo, int id)
{
	if (id % 2 != 0)
	{
		pthread_mutex_lock(&philo->st->print_mutex);
		printf("%d has taken a fork\n", id);
		pthread_mutex_unlock(&philo->st->print_mutex);
		ft_eat(philo->st, philo->st->philo[id].left_fork,
			philo->st->philo[id].right_fork, philo->id);
	}
	else
	{
		usleep(10);
		pthread_mutex_lock(&philo->st->print_mutex);
		printf("%d has taken a fork\n", id);
		pthread_mutex_unlock(&philo->st->print_mutex);
		ft_eat(philo->st, philo->st->philo[id].left_fork,
			philo->st->philo[id].right_fork, philo->id);
	}
}
