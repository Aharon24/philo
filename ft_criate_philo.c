#include "philo.h"

void	ft_setupe_fork_p(t_args *st, t_philo *philo_)
{
	int		i;
	int		n;

	n = st->num_philos;
	i = 0;
	while (i < st->num_philos)
	{
		if (i == 0)
		{
			philo_[i].left_fork = i;
			philo_[i].right_fork = (i + 1) % n;
			i++;
		}
		else
		{
			philo_[i].left_fork = i;
			philo_[i].right_fork = (i + 1) % n;
			i++;
		}
	}
	i = 0;
	// ft_print_fork(i,start,st->num_philos);
}

void	ft_create(t_args *st, t_philo *philo)
{
	int			i;

	i = 0;
	ft_setupe_fork_p(st, st->philo); //????????;
	while (i < st->num_philos)
	{
    	philo[i].st = st;
		philo->id = i;
    	i++;
	}
	i = 0;
	while (i < st->num_philos)
	{
		 pthread_create(&st->philo[i].threads, NULL,
			my_thread_function, &philo[i]);
		i++;
	}
	i = 0;
	while (i < st->num_philos)
	{
		pthread_join(philo[i].threads, NULL);
		i++;
	}
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
	st->someone_died = 1;

}

void	*my_thread_function(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->st->someone_died)
	{
		ft_get_fork(philo,philo->id);
		if (ft_sleep(12, philo) == 0)
			break ;
		if (ft_think(12, philo) == 0)
			break ;
	}
	printf("philo end died \n");
	return (NULL);
}

void	ft_criate_philo(t_args *st)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * st->num_philos);
	st->philo = philo;
	ft_create(st, st->philo);
}
