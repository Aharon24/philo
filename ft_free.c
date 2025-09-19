#include "philo.h"

void	ft_free_and_end(t_args *st)
{
	int	i;

	i = 0;
	while (i < st->num_philos)
	{
		pthread_mutex_destroy(&st->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&st->print_mutex);
	pthread_mutex_destroy(&st->deat);
	pthread_mutex_destroy(&st->time_t);
	free(st->forks);
	free(st);
}
