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
				ft_daid(&st->print_mutex, i + 1, ft_timestamp(&st->start));
				pthread_mutex_unlock(&st->time_t);
				pthread_mutex_unlock(&st->deat);
				st->free = 1;
				return (NULL);
			}
			pthread_mutex_unlock(&st->deat);
			i++;
		}
		usleep(500);
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
	i = 0;
	while (i < st->num_philos)
	{
		philo_[i].eat_count = 0;
		philo_[i].st = st;
		philo_[i].id = i;
		philo_[i].last_meal = ft_timestamp(&st->start);
		if (st->ac == 1)
			philo_[i].eat_count = st->must_eat;
		i++;
	}
}

void	ft_create(t_args *st, t_philo *philo, int i)
{
	ft_setupe_fork_p(st, st->philo);
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

	gettimeofday(&st->start, NULL);
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
		return ;
	}
	st->philo = philo;
	st->ac = 0;
	ft_create(st, st->philo, i);
	if (st->free == 1)
		free(philo);
}
