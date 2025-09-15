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