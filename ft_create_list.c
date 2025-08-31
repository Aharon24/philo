#include "philo.h"

t_philo	*ft_crate_list(t_args *st)
{
	t_philo	*start;
	t_philo	*head;
	int		i;

	i = 0;
	start = malloc(sizeof(t_philo));
	start->id = i;
	head = start;
	i++;
	while (i < st->num_philos)
	{
		start->next = NULL;
		if (i != st->num_philos)
			start->next = malloc(sizeof(t_philo));
		start = start->next;
		start->id = i;
		i++;
	}
	start->next = NULL;
	return (head);
}

void	ft_print_list(t_philo *p)
{
	t_philo	*x;

	x = p;
	while (x)
	{
		printf("%d", x->id);
		printf(" -> ");
		x = x->next;
	}
	printf("NULL\n");
}
