#include "philo.h"

t_philo *ft_crate_list(t_args *st)
{
    t_philo *start;
    t_philo *head;
    int     i;

    i = 0; 
    start =  malloc(sizeof(t_philo));
    head = start;
    start->id = i;
    i++;
    while (i < st->num_philos)
    {
        start->next = NULL;
        start->id = i;
        if (i != st->num_philos)
            start->next = malloc(sizeof(t_philo));
        start = start->next;
        i++;
    }
    return (head);
}   

void ft_print_list(t_philo *p)
{
    t_philo *x;

    x = p;
    while (x)
    {
        printf("%d",x->id);
        printf("->");
        x = x->next;
    }
    printf("NULL\n");

}