#include "philo.h"

void	ft_work_philo(t_args *st)
{
	ft_criate_philo(st);
}

int	ft_chesk_argument(t_args *st)
{
	int	c;

	c = ft_chek_list(st);
	if (c == 0)
		return (0);
	return (1);
}

void	ft_philo(int ac, char **argv)
{
	t_args	*st;
	int		c;

	c = 0;
	st = malloc(sizeof(t_args));
	printf("int argc %d\n", ac);
	st->num_philos = ft_atoi(argv[1]);
	st->time_to_die = ft_atoi(argv[2]);
	st->time_to_eat = ft_atoi(argv[3]);
	st->time_to_sleep = ft_atoi(argv[4]);
	if (ac == 6)
    	st->must_eat = ft_atoi(argv[5]);
	else
    	st->must_eat = -1;
	c = ft_chesk_argument(st);
	if (c == 1)
		ft_work_philo(st);
	else
		printf("ERROR\n");
	ft_free_and_end(st);
}

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		ft_philo(argc, argv);
	}
	else
		printf("Error: invalid number of arguments.\n");
}
