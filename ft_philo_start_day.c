#include "philo.h"

void ft_eat(t_args *st, int left, int rigth)
{
	pthread_mutex_lock(&st->forks[left]);
	pthread_mutex_lock(&st->forks[rigth]);
	printf("2 ->>>>>>>>\n");
	usleep(5000000);
	pthread_mutex_unlock(&st->forks[left]);
	pthread_mutex_unlock(&st->forks[rigth]);
} 
void ft_get_fork(t_philo *philo, int id)
{
	if (id % 2 != 0)
		ft_eat(philo->st,  philo->st->philo[id].left_fork,philo->st->philo[id].right_fork);
	if (id % 2 != 0)
		return ;
	if (id % 2 == 0)
		ft_eat(philo->st,  philo->st->philo[id].left_fork,philo->st->philo[id].right_fork);
}

void	ft_philo_start_day(t_args *st, t_philo *philo)
{
	int	i;

	i = 0;
	printf("%d\n", st->philo->id);
	//ft_print_fork(i,st->philo,st->num_philos);
	while (1)
	{
		//ft_get_fork(st,i);
		//ft_sleep(st->time_to_sleep, philo);
		if (philo[i].threads)
		{
			printf("%d\n",i);
			printf("New List\n");
			i++;
		}
		else
			i = 0;
	}
}
