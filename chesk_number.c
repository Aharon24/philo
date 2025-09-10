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

int	ft_atoi(const char *str)
{
	int	i;
	int	z;
	int	result;

	i = 0;
	z = 1;
	result = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			z = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		return (0);
	return (result * z);
}

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
