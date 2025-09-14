#include "philo.h"

long	ft_timestamp(t_time_p *start)
{
	struct timeval	current;
	long			ms;

	gettimeofday(&current, NULL);
	ms = (current.tv_sec - start->tv_sec) * 1000
		+ (current.tv_usec - start->tv_usec) / 1000;
	return (ms);
}

void	ft_daid(pthread_mutex_t *l, int id)
{
	pthread_mutex_lock(l);
	printf("%d diedn\n", id);
	pthread_mutex_unlock(l);
}

void	ft_get_my_time(t_time_p *t)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	t->tv_sec = tv.tv_sec;
	t->tv_usec = tv.tv_usec;
}

void	ft_time_start(t_args *st)
{
	ft_get_my_time(&st->t_start);
}
