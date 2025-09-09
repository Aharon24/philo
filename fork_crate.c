#include "philo.h"

void	ft_print_fork(int i, t_philo *start, int phi_caunt)
{
	i = 0;
	while (i < phi_caunt)
	{
		printf(" left %d  right %d\n", start[i].left_fork, start[i].right_fork);
		i++;
	}
}
