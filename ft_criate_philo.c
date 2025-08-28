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
    t_philo *head;
    t_philo *current;

    i = 0;
    st->philo  = ft_crate_list(st);
    head = st->philo;
    current = head;
    //ft_print_list(st->philo);
    while (i < st->num_philos)
    {
        pthread_create(&current->threads,NULL,my_thread_function,&st->time_to_die);
        printf("%d\n",i);
        current = current->next;
        i++;
    }
    i = 0;
    current = head;
    while(i < st->num_philos)
    {
        pthread_join(current->threads,NULL);
        current = current->next;
        i++;
    }
   // ft_setupe_fork_p(st, st->philo);
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
    static int j;

    j = 0;
    i = *(int *)arg;  // приводим void* к int*
        printf("philo j %d i %d\n", j,i);
            j++;

    return NULL;
}

void ft_criate_philo(t_args *st)
{

    ft_create(st);
}