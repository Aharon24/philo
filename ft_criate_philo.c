#include "philo.h"

void *my_thread_function(void *arg) 
{
    int i;
    
    i = *(int *)arg;
    printf("philo %d\n",i);
    return NULL;
}


void ft_create(t_args *st, pthread_t *threads)
{
    int i;

    i = 0;
    st->ids = malloc(st->num_philos * sizeof(int));
    while (i <st->num_philos)
    {
        st->ids[i] = i;
        pthread_create(&threads[i],NULL,my_thread_function,&st->ids[i]);
        i++;
    }
    i = 0;
    while(i < st->num_philos)
    {
        pthread_join(threads[i],NULL);
        i++;
    }
}

void ft_criate_philo(t_args *st)
{

    pthread_t threads[st->num_philos];

    ft_create(st,threads);
}