#include "philo.h"

void ft_think(t_args *st, int id, long time)
{
	if (ft_c_d(&st->deat, st->someone_died) == 1)
		return ;
    pthread_mutex_lock(&st->print_mutex);
    printf("%ld %d is thinking\n", time, id + 1);
    pthread_mutex_unlock(&st->print_mutex);
}

// void	ft_think(t_args *st,int id)
// {
// 	if (ft_c_d(&st->deat, st->someone_died) == 1)
// 		return ;
// 	pthread_mutex_lock(&st->deat);
// 	if (st->someone_died == -1)
// 	{
// 		pthread_mutex_lock(&st->print_mutex);
// 		printf("%ld %d is thinking\n",
// 			st->time += ft_timestamp(&st->t_start), id);
// 		pthread_mutex_unlock(&st->print_mutex);
// 	}
// 	pthread_mutex_unlock(&st->deat);
// }

void	ft_sleep(t_args *st, int id)
{
	if (ft_c_d(&st->deat, st->someone_died) == 1)
		return ;
	pthread_mutex_lock(&st->time_t);
	ft_get_my_time(&st->t_start);
	usleep(1000 * st->time_to_sleep);
	ft_get_my_time(&st->t_end);
	st->tt = (st->t_end.tv_sec - st->t_start.tv_sec) * 1000
	+ (st->t_end.tv_usec - st->t_start.tv_usec) / 1000;
	st->time += st->tt;
	if (st->tt > st->time_to_die)
		st->someone_died = 1;
	if (ft_c_d(&st->deat,st->someone_died) == 1)
		return ;
	ft_print_all(st, st->time, id, 3);
	pthread_mutex_unlock(&st->time_t);
}

void	ft_eat(t_args *st, int left, int rigth, int id)
{
	if (ft_c_d(&st->deat, st->someone_died) == 1)
		return ;
	pthread_mutex_lock(&st->forks[left]);
	ft_print_all(st, st->time, id, 1);
	if (pthread_mutex_trylock(&st->forks[rigth]) != 0)
	{
		st->someone_died = 1;
		pthread_mutex_unlock(&st->forks[left]);
		return ;
	}
	ft_print_all(st, st->time, id, 1);
	usleep(1000 * st->time_to_eat);
	ft_get_my_time(&st->t_end);
	st->tt = (st->t_end.tv_sec - st->t_start.tv_sec) * 1000
	+ (st->t_end.tv_usec - st->t_start.tv_usec) / 1000;
	st->time += st->tt;
	pthread_mutex_lock(&st->deat);
	if (st->tt > st->time_to_die)
		st->someone_died = 1;
	if (st->someone_died != -1)
	{
		pthread_mutex_unlock(&st->forks[left]);
		pthread_mutex_unlock(&st->forks[rigth]);
		pthread_mutex_unlock(&st->deat);
		return ;
	}
	ft_print_all(st, st->time, id, 2);
	pthread_mutex_unlock(&st->deat);
	pthread_mutex_unlock(&st->forks[left]);
	pthread_mutex_unlock(&st->forks[rigth]);
}

int	ft_get_fork(t_philo *philo, int id)
{
	if (ft_c_d(&philo->st->deat, philo->st->someone_died) == 1)
		return (3);
	if (id % 2 != 0)
	{
		//printf("------------------ 1\n");
		ft_eat(philo->st, philo->st->philo[id].left_fork,
			philo->st->philo[id].right_fork, id);
	}
	else
	{
		//printf("--------------- 2\n");
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
        usleep(100);
	while (1)
	{
		if (ft_c_d(&philo->st->deat, philo->st->someone_died) == 1)
			return (NULL);
		ft_get_fork(philo, philo->id);
		ft_sleep(philo->st, philo->id);
		ft_think(philo->st, philo->id, philo->st->time);
	}
	return (NULL);
}
