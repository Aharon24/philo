#include "philo.h"

void ft_setupe_fork_p(t_args *st, t_philo *philo_)
{
    int     i;
    int     n;
    t_philo *start;

    n = st->num_philos;
    i = 0;
    start =  philo_;
    while (i < st->num_philos)
    {
        if (i == 0)
        {
            philo_->left_fork = i;
            philo_->right_fork = (i + 1) % n;
        }
        else
        {
            philo_ = philo_->next;
            philo_->left_fork = i;
            philo_->right_fork = (i + 1) % n;
        }
    }
    i = 0;
    while( i < st->num_philos)
    {
        printf(" left %d  right %d ",start->left_fork,start->right_fork);
        start = start->next;
    }
}

void ft_create(t_args *st)
{
    int i;
    t_philo *start;
    t_philo *j;

    i = 0;
    st->philo = malloc(sizeof(t_philo));
    start = st->philo;
    j = st->philo;
    st->philo->next = NULL;
    while (i < st->num_philos)
    {
        pthread_create(&st->philo->threads,NULL,my_thread_function,&st->ids[i]);
        st->philo = st->philo->next;
        st->philo = malloc(sizeof(t_philo));
        i++;
    }
    i = 0;
    while(i < st->num_philos)
    {
        pthread_join(j->threads,NULL);
        j = j->next;
        i++;
    }
    ft_setupe_fork_p(st, start);
}

void ft_create_mutex(t_args *st)
{
    int i;

    st->forks =  malloc(sizeof(pthread_mutex_t) * st->num_philos);
    if (!st->forks)
    {
        printf("Error: malloc failed for forks\n");
        return ;
    }
    i = 0;
    while (i < st->num_philos)
    {
        pthread_mutex_init(&st->forks[i], NULL);
        i++;
    }
    st->someone_died = 0;
}

void *my_thread_function(void *arg) 
{
    int i;

    i = *(int *)arg;  // приводим void* к int*
    if (i)
        printf("philo %d\n", i);
    else
        printf("i\n");

    return NULL;
}



void ft_criate_philo(t_args *st)
{

    ft_create(st);
}