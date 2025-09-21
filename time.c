#include "philo.h"

void	ft_time(t_args *st, int id)
{
	long	now;

	pthread_mutex_lock(&st->time_t);
	now = ft_timestamp(&st->start);
	if (now - st->philo[id].last_meal > st->time_to_die)
	{
		pthread_mutex_lock(&st->deat);
		st->someone_died = 1;
		pthread_mutex_unlock(&st->deat);
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

void	ft_get_my_time(t_time_p *t)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	t->tv_sec = tv.tv_sec;
	t->tv_usec = tv.tv_usec;
}
