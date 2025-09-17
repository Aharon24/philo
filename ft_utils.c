#include "philo.h"

int	ft_c_d(pthread_mutex_t	*d, int check)
{
	pthread_mutex_lock(d);
	if (check != -1)
	{
		pthread_mutex_unlock(d);
		return (1);
	}
	pthread_mutex_unlock(d);
	return (0);
}

void	ft_unlock(pthread_mutex_t *l, pthread_mutex_t *r, pthread_mutex_t *d)
{
	pthread_mutex_unlock(l);
	pthread_mutex_unlock(r);
	pthread_mutex_unlock(d);
}

void	ft_check_death(t_args *st, int id)
{
	long	now;

	now = ft_timestamp(&st->start);
	pthread_mutex_lock(&st->deat);
	if (now - st->philo[id].last_meal
		> st->time_to_die && st->someone_died == -1)
	{
		st->someone_died = id;
		printf("%ld %d died\n", now, id);
	}
	pthread_mutex_unlock(&st->deat);
}

void	ft_update(t_args *st, int id)
{
	pthread_mutex_lock(&st->deat);
	st->philo[id].last_meal = ft_timestamp(&st->start);
	pthread_mutex_unlock(&st->deat);
}
