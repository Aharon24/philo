#include "philo.h"

int	ft_chek_atoi(int n)
{
	if (n <= 0)
		return (0);
	if (n == 2147483647)
		return (0);
	if (n == -2147483648)
		return (0);
	return (1);
}

int	ft_chek_list(t_args *st)
{
	if (!ft_chek_atoi(st->num_philos))
		return (0);
	if (!ft_chek_atoi(st->time_to_die))
		return (0);
	if (!ft_chek_atoi(st->time_to_eat))
		return (0);
	if (!ft_chek_atoi(st->time_to_sleep))
		return (0);
	if (st->must_eat != -1 && !ft_chek_atoi(st->must_eat))
		return (0);
	return (1);
}
