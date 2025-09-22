#include "philo.h"

void	ft_time(t_args *st, int id)
{
	long	now;

	pthread_mutex_lock(&st->time_t);
	now = ft_timestamp(&st->start);
	if (now - st->philo[id].last_meal > st->time_to_die)
	{
		pthread_mutex_unlock(&st->time_t);
		pthread_mutex_lock(&st->deat);
		st->someone_died = 1;
		pthread_mutex_unlock(&st->deat);
		return ;
	}
	pthread_mutex_unlock(&st->time_t);
}

long	ft_timestamp(struct timeval *start)
{
	struct timeval	current;
	long			ms;

	gettimeofday(&current, NULL);
	ms = (current.tv_sec - start->tv_sec) * 1000
		+ (current.tv_usec - start->tv_usec) / 1000;
	return (ms);
}

void	ft_daid(pthread_mutex_t *l, int id, long time, t_args *st)
{
	pthread_mutex_lock(l);
	if (st->someone_died == 2)
	{
		pthread_mutex_unlock(l);
		return ;
	}
	pthread_mutex_unlock(l);
	pthread_mutex_lock(l);
	printf("%ld %d diedn\n", time, id);
	pthread_mutex_unlock(l);
}

int	get_someone_died(t_args *st)
{
	int	val;

	pthread_mutex_lock(&st->deat);
	val = st->someone_died;
	pthread_mutex_unlock(&st->deat);
	return (val);
}

void	set_someone_died(t_args *st, int id)
{
	pthread_mutex_lock(&st->deat);
	st->someone_died = id;
	pthread_mutex_unlock(&st->deat);
}
