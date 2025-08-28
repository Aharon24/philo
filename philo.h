#include <stdio.h>        // printf
#include <stdlib.h>       // malloc, free
#include <string.h>       // memset
#include <unistd.h>       // usleep, write
#include <sys/time.h>     // gettimeofday
#include <pthread.h>      // потоки и мьютексы
#include <stdio.h>

typedef struct s_args
{
	int	num_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	int *ids;
}	t_args;


//ft_free.c
void ft_free_and_end(t_args *st);
void ft_free_arr(int **arr);

//ft_create_philo.c
void	*my_thread_function(void *arg);
void	ft_create(t_args *st, pthread_t *threads);
void	ft_criate_philo(t_args *st);


/// philo.c
void	ft_philo(int ac, char **Argv);
int		ft_chesk_argument(t_args *st);

//chesk_number.c
int		ft_chek_atoi(int n);
int		ft_chek_list(t_args *st);

// ft_atoi.c
int		ft_atoi(const char *str);