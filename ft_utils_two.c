#include "philo.h"

int ft_chek_think(t_args *st, int check)
{
	pthread_mutex_lock(&st->deat);
	if (check != -1)
	{
		pthread_mutex_unlock(&st->deat);
		return (1);
	}
	pthread_mutex_unlock(&st->deat);
	return (0);
}
	
int ft_diper_one(t_args *st, int id, long time)
{
	if (ft_chek_think(st,st->someone_died) == 1)
	{
		pthread_mutex_unlock(&st->print_mutex);
		return (1);
	}	
	printf("%ld %d has taken a fork\n", time, id + 1);
	return (0);
}

int ft_diper_two(t_args *st, int id, long time)
{
	if (ft_chek_think(st,st->someone_died) == 1)
	{
		pthread_mutex_unlock(&st->print_mutex);
		return (1);	
	}
	printf("%ld %d is eating\n", time, id + 1);
	return (0);
}



int ft_diper_three(t_args *st, int id, long time)
{
	if (ft_chek_think(st,st->someone_died) == 1)
	{
		pthread_mutex_unlock(&st->print_mutex);
		return (1);	
	}
	printf("%ld %d is sleeping\n", time, id + 1);
	return (0);
}

int ft_diper_four(t_args *st, int id , long time)
{
	if (ft_chek_think(st,st->someone_died) == 1)
	{
		pthread_mutex_unlock(&st->print_mutex);
		return (1);	
	}
	printf("%ld %d is thinking\n", time, id + 1);
		return (0);
}