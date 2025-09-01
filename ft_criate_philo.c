#include "philo.h"

void	ft_setupe_fork_p(t_args *st, t_philo *philo_)
{
	int		i;
	int		n;
	t_philo	*start;

	n = st->num_philos;
	i = 0;
	start = philo_;
	while (i < st->num_philos)
	{
		if (i == 0)
		{
			philo_->left_fork = i;
			philo_->right_fork = (i + 1) % n;
			i++;
		}
		else
		{
			philo_ = philo_->next;
			philo_->left_fork = i;
			philo_->right_fork = (i + 1) % n;
			i++;
		}
	}
	i = 0;
	// ft_print_fork(i,start,st->num_philos);
}

void	ft_create(t_args *st, t_philo *philo)
{
	int			i;
	pthread_t	threads_i;

	i = 0;
	while (i < st->num_philos)
	{
		pthread_create(&st->philo[i], NULL,
			my_thread_function, &st->time_to_die);
		i++;
	}
	i = 0;
	while (i < st->num_philos)
	{
		pthread_join(philo[i].threads, NULL);
		i++;
	}
	ft_setupe_fork_p(st, st->philo);
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
	st->someone_died = 0;
}

void	*my_thread_function(void *arg)
{
	int	i;

	i = *(int *)arg;
	printf("philo-> i %d\n", i);
	return (NULL);
}

void	ft_criate_philo(t_args *st)
{
	t_philo philo[st->num_philos];
	st->philo = philo;
	ft_create(st,st->philo);
}
