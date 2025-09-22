#include "philo.h"

int	ft_c_d(pthread_mutex_t	*d, int check, t_philo *philo)
{
	int	status;

	pthread_mutex_lock(d);
	if (check == 1 || check == 2)
	{
		pthread_mutex_unlock(d);
		return (1);
	}
	pthread_mutex_unlock(d);
	status = get_someone_died(philo->st);
	if (status == 1 || status == 2)
		return (1);
	return (0);
}

void	ft_unlock(pthread_mutex_t *l, pthread_mutex_t *r)
{
	pthread_mutex_unlock(l);
	pthread_mutex_unlock(r);
}

void	ft_check_death(t_args *st, int id)
{
	long	now;

	now = ft_timestamp(&st->start);
	pthread_mutex_lock(&st->deat);
	if (now - st->philo[id].last_meal
		> st->time_to_die && st->someone_died == -1)
	{
		st->someone_died = 1;
		pthread_mutex_lock(&st->print_mutex);
		printf("%ld %d died\n", now, id);
		pthread_mutex_unlock(&st->print_mutex);
	}
	pthread_mutex_unlock(&st->deat);
}

void	ft_update(t_args *st, int id)
{
	pthread_mutex_lock(&st->deat);
	st->philo[id].last_meal = ft_timestamp(&st->start);
	pthread_mutex_unlock(&st->deat);
}

void	ft_simple_sleep(int ms, t_args *st)
{
	long	start;

	start = ft_timestamp(&st->start);
	while (ft_timestamp(&st->start) - start < ms)
		usleep(500);
}
