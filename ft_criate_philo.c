#include "philo.h"

void *ft_monitor(void *arg)
{
	t_args	*st;
	int		i;

	st = (t_args *)arg;
	while (1)
	{
		i = 0;
		while (i < st->num_philos)
		{
			pthread_mutex_lock(&st->death_mutex);
			if (st->someone_died != -1)
			{
				pthread_mutex_unlock(&st->death_mutex);
				ft_daid(&st->print_mutex,i+1);
				return (NULL);
			}
			pthread_mutex_unlock(&st->death_mutex);
			i++;
		}
	}
	return	(NULL);
}


void	ft_setupe_fork_p(t_args *st, t_philo *philo_)
{
	int		i;
	int		n;

	n = st->num_philos;
	i = 0;
	while (i < st->num_philos)
	{
		philo_[i].left_fork = i;
		philo_[i].right_fork = (i + 1) % n;
		i++;
	}
}

void	ft_create(t_args *st, t_philo *philo)
{
	int			i;
	i = 0;
	
	ft_setupe_fork_p(st, st->philo);
	while (i < st->num_philos)
	{
		philo[i].st = st;
		philo[i].id = i;
		philo[i].last_meal = 0;
		i++;
	}
	i = 0;
	while (i < st->num_philos)
	{
		pthread_create(&philo[i].threads, NULL,
			my_thread_function, &st->philo[i]);
		i++;
	}
	i = 0;
	pthread_create(&st->monitor, NULL,
			ft_monitor, st);
	while (i < st->num_philos)
	{
		pthread_join(philo[i].threads, NULL);
		i++;
	}
	pthread_join(st->monitor, NULL);
}

void	ft_create_mutex(t_args *st)
{
	int	i;

	st->forks = malloc(sizeof(pthread_mutex_t) * st->num_philos);
	if (!st->forks)
	{
		printf("Error: malloc failed for forks\n");
		return ;
	}
	i = 0;
	while (i < st->num_philos)
	{
		pthread_mutex_init(&st->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&st->print_mutex, NULL);
	pthread_mutex_init(&st->death_mutex, NULL);
	pthread_mutex_init(&st->time_t, NULL);
	st->someone_died = -1;
}

void	ft_criate_philo(t_args *st)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * st->num_philos);
	st->philo = philo;
	ft_create(st, st->philo);
}
