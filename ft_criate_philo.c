#include "philo.h"

void	*ft_monitor(void *arg)
{
	t_args	*st;
	int		i;

	st = (t_args *)arg;
	while (1)
	{
		i = 0;
		while (i < st->num_philos)
		{
			pthread_mutex_lock(&st->deat);
			if (st->someone_died != -1)
			{
				pthread_mutex_lock(&st->time_t);
				pthread_mutex_unlock(&st->deat);
				ft_daid(&st->print_mutex, i + 1, st->time);
				pthread_mutex_unlock(&st->time_t);
				return (NULL);
			}
			pthread_mutex_unlock(&st->deat);
			i++;
		}
	}
	return (NULL);
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
	st->old_time = ft_timestamp(&st->time_clock);
}

void	ft_create(t_args *st, t_philo *philo, int i)
{
	ft_setupe_fork_p(st, st->philo);
	while (i < st->num_philos)
	{
		philo[i].st = st;
		philo[i].id = i;
		philo[i].last_meal =  ft_timestamp(&philo[i].t_start);
		i++;
	}
	i = 0;
	while (i < st->num_philos)
	{
		pthread_create(&philo[i].threads, NULL,
			my_thread_function, &philo[i]);
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
	pthread_mutex_init(&st->deat, NULL);
	pthread_mutex_init(&st->time_t, NULL);
	st->someone_died = -1;
}

void	ft_criate_philo(t_args *st)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * st->num_philos);
	if (!philo)
	{
		perror("ERROR MEMORY\n");
		return;
	}
	st->philo = philo;
	ft_create(st, st->philo, i);
}
