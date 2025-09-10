#include "philo.h"

void ft_daid(pthread_mutex_t *l, pthread_mutex_t *u,int id)
{
	pthread_mutex_lock(l);
	printf("%d diedn\n",id);
	pthread_mutex_unlock(u);
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
	//printf("%ld", st->t_start.tv_sec + st->t_start.tv_usec);
}
