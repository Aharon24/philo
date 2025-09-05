#include "philo.h"

void ft_get_my_time(t_time_p *t)
{
	struct  timeval tv;
	gettimeofday(&tv,NULL);
	
	t->tv_sec = tv.tv_sec;
	t->tv_usec = tv.tv_usec;
	
}

void	ft_time_start(t_args *st)
{
	ft_get_my_time(&st->t_Start);
	printf("%ld",st->t_Start.tv_sec + st->t_Start.tv_usec);
	
}
