#include "philo.h"

int ft_sleep(int time, t_philo *philo)
{
    printf("think sleep  %d p ->  %d\n",time,philo->id);
    if (philo->st->someone_died)
        return (1);
    philo->st->someone_died = 0;
    return(0);
}

int ft_think(int time, t_philo *philo)
{
    printf("think time  %d p ->  %d\n",time,philo->id);
    if (philo->st->someone_died)
        return (1);
    return (0); 
} 