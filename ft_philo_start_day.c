#include "philo.h"

// void ft_eat(t_args *st, int id, t_philo *start, int i)
// {
// } 
// void ft_get_fork(t_args *st)
// {
// }

void	ft_philo_start_day(t_args *st, t_philo *philo)
{
	int	i;

	i = 0;
	printf("%d\n", st->philo->id);
	//ft_print_fork(i,st->philo,st->num_philos);
	while (1)
	{
		//ft_get_fork_(st);
		//ft_sleep(st->time_to_sleep, philo);
		if (philo[i].threads)
		{
			printf("New List\n");
			i++;
		}
		else
			return ;
	}
}
