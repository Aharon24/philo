#include "philo.h"

int ft_chek_atoi(int n)
{
	if (n <= 0)
		return (0);
	if (n == 2147483647)
		return (0);
	if( n == -2147483648)
		return (0);
	return (1);
}

int ft_chek_list(t_args *st)
{
	int n;

	n = ft_chek_atoi(st->num_philos);
	if (n == 0)
		return (0);
	n = ft_chek_atoi(st->time_to_die);
	if (n == 0)
		return (0);
	n = ft_chek_atoi(st->time_to_eat);
	if (n == 0)
		return (0);
	n = ft_chek_atoi(st->time_to_sleep);
	if (n == 0)
		return (0);
	n = ft_chek_atoi(st->must_eat);
	if (n == 0)
		return (0);
	return (1);

}