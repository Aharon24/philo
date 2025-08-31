#include "philo.h"

// void ft_eat(t_args *st, int id, t_philo *start, int i)
// {

// } 

// void ft_get_fork_eat(t_args *st)
// {
// }

void ft_philo_start_day(t_args *st,t_philo *philo)
{
	t_philo *head;

	head  = philo;
	ft_print_list(st->philo);
	ft_print_fork(0,st->philo,st->num_philos);
	while(1)
	{
		//ft_get_fork_eat(st);
		//ft_sleep(st->time_to_sleep, philo);

		philo = philo->next;
		if(philo->next == NULL)
		{
			philo = head;
			printf("New List\n");
		}
	}

}