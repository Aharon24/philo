#include "philo.h"

// int ft_fork_crate(int id, int number, t_args *st)
// {
//     int n;

//     n = st->num_philos;
// }

void	ft_print_fork(int i, t_philo *start, int phi_caunt)
{
	i = 0;
	while (i < phi_caunt)
	{
		printf(" left %d  right %d\n", start[i].left_fork, start[i].right_fork);
		i++;
	}
}
