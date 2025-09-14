#include "philo.h"

void ft_think(t_args *st,int id)
{	
	pthread_mutex_lock(&st->death_mutex);
	if (st->someone_died != -1)
    	return ;
	pthread_mutex_unlock(&st->death_mutex);
    pthread_mutex_lock(&st->print_mutex);
    printf("%ld %d is thinking\n",st->time += ft_timestamp(&st->t_start), id);
    pthread_mutex_unlock(&st->print_mutex);
}


void	ft_sleep(t_args *st, int id)
{
	pthread_mutex_lock(&st->death_mutex);
	if (st->someone_died != -1)
	{
    	pthread_mutex_unlock(&st->death_mutex);
    	return ;
	}
	pthread_mutex_unlock(&st->death_mutex);

	pthread_mutex_lock(&st->time_t);
	ft_get_my_time(&st->t_start);
	usleep(1000 * st->time_to_sleep);
	ft_get_my_time(&st->t_end);
	st->tt = (st->t_end.tv_sec - st->t_start.tv_sec) * 1000
             + (st->t_end.tv_usec - st->t_start.tv_usec) / 1000;
	pthread_mutex_lock(&st->death_mutex);
	st->time += st->tt;
	if (st->tt > st->time_to_die)
		st->someone_died = 1;
	if (st->someone_died != -1) 
	{
			pthread_mutex_unlock(&st->time_t);
			pthread_mutex_unlock(&st->death_mutex);
			return ;
	}
	pthread_mutex_unlock(&st->death_mutex);
	pthread_mutex_lock(&st->print_mutex);
	printf("%ld %d is sleeping\n",st->time, id);
	pthread_mutex_unlock(&st->print_mutex);
	pthread_mutex_unlock(&st->time_t);
}

void	ft_eat(t_args *st, int left, int rigth, int id)
{
	pthread_mutex_lock(&st->death_mutex);
	if (st->someone_died != -1)
	{ 
    	pthread_mutex_unlock(&st->death_mutex);
    	return ;
	}
	pthread_mutex_unlock(&st->death_mutex);
	
	pthread_mutex_lock(&st->time_t);
	ft_get_my_time(&st->t_start);


	pthread_mutex_lock(&st->forks[left]);
	pthread_mutex_lock(&st->print_mutex);
	printf(" l %ld %d has taken a fork\n", st->time, id);
	pthread_mutex_unlock(&st->print_mutex);
	printf ("2\n");
	pthread_mutex_lock(&st->forks[rigth]);
	pthread_mutex_lock(&st->print_mutex);
	printf("%ld %d has taken a fork\n", st->time, id);
	pthread_mutex_unlock(&st->print_mutex);

	pthread_mutex_lock(&st->print_mutex);
	printf("%ld %d is eating\n", st->time, id);
	pthread_mutex_unlock(&st->print_mutex);
	usleep(1000 * st->time_to_eat);
	ft_get_my_time(&st->t_end);
	st->tt = (st->t_end.tv_sec - st->t_start.tv_sec) * 1000
	+ (st->t_end.tv_usec - st->t_start.tv_usec) / 1000;
	st->time += st->tt;
	
	pthread_mutex_lock(&st->death_mutex);
	if (st->tt > st->time_to_die)
		st->someone_died = 1;
	pthread_mutex_unlock(&st->death_mutex);
	pthread_mutex_unlock(&st->forks[left]);
	pthread_mutex_unlock(&st->forks[rigth]);
	pthread_mutex_unlock(&st->time_t);
	pthread_mutex_unlock(&st->death_mutex);
	
	if (st->someone_died != -1)
	{
		pthread_mutex_unlock(&st->forks[left]);
		pthread_mutex_unlock(&st->forks[rigth]);
		pthread_mutex_unlock(&st->time_t);
    	pthread_mutex_unlock(&st->death_mutex);
    	return ;
	}
}

int	ft_get_fork(t_philo *philo, int id)
{
	if (philo->st->someone_died != -1)
			return (3);
	if (id % 2 != 0)
	{
		ft_eat(philo->st, philo->st->philo[id].left_fork,
			philo->st->philo[id].right_fork, id);
	}
	else
	{
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
	pthread_mutex_lock(&philo->st->death_mutex);
	if (philo->st->someone_died != -1)
		return (NULL);
	pthread_mutex_unlock(&philo->st->death_mutex);
	if (philo->id % 2 == 0)
        usleep(50);
	while (1)
	{
		pthread_mutex_lock(&philo->st->death_mutex);
        if (philo->st->someone_died != -1)
        {
			if (philo->st->someone_died != -1) 
			{
				printf("p %d d %d\n",philo->id, philo->st->someone_died);
				ft_daid(&philo->st->print_mutex, &philo->st->print_mutex,philo->id);
			}
            pthread_mutex_unlock(&philo->st->death_mutex);
            return (NULL);
        }
		pthread_mutex_unlock(&philo->st->death_mutex);
		ft_get_fork(philo, philo->id);
		ft_sleep(philo->st, philo->id);
		ft_think(philo->st,philo->id);
	}
	return (NULL);
}
