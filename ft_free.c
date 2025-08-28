#include "philo.h"

void ft_free_and_end(t_args *st)
{
    if(st->ids)
		free(st->ids);
    free(st);
}

