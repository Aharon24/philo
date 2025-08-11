#include <stdio.h>        // printf
#include <stdlib.h>       // malloc, free
#include <string.h>       // memset
#include <unistd.h>       // usleep, write
#include <sys/time.h>     // gettimeofday
#include <pthread.h>      // потоки и мьютексы
#include <stdio.h>
#include "Libft/libft.h"

typedef struct s_args
{
	int	num_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
}	t_args;

/// philo.c
void	ft_philo(int ac, char **Argv);
int		ft_chesk_argument(t_args *st);

//chesk_number.c
int 	ft_chek_atoi(int n);
int 	ft_chek_list(t_args *st);