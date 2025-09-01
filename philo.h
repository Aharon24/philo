#include <stdio.h>        // printf
#include <stdlib.h>       // malloc, free
#include <string.h>       // memset
#include <unistd.h>       // usleep, write
#include <sys/time.h>     // gettimeofday
#include <pthread.h>      // потоки и мьютексы
#include <stdio.h>

typedef struct s_time
{
	time_t		time;
	suseconds_t	seconds;
}	t_time;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	pthread_t		threads;
	struct s_philo	*next;

}	t_philo;

typedef struct s_args
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				*ids;
	int				someone_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	t_philo			*philo;
	t_time			time;
}	t_args;

//ft_free.c
void	ft_free_and_end(t_args *st);
void	ft_free_arr(int **arr);

//ft_create_philo.c
void	*my_thread_function(void *arg);
void	ft_create(t_args *st, t_philo *s_philo);
void	ft_setupe_fork_p(t_args *st, t_philo *philo_);
void	ft_criate_philo(t_args *st);
void	ft_create_mutex(t_args *st);

/// philo.c
void	ft_philo(int ac, char **Argv);
int		ft_chesk_argument(t_args *st);

//chesk_number.c
int		ft_chek_atoi(int n);
int		ft_chek_list(t_args *st);

// ft_atoi.c
int		ft_atoi(const char *str);

//fork_crate.c
//int ft_fork_crate(int id, int number, t_args *st); ???? 
void	ft_print_fork(int i, t_philo *start, int phi_caunt);

///ft_create_list.c
void	ft_print_list(t_philo *p);
t_philo	*ft_crate_list(t_args *st);

//ft_philo_start_day.c

void	ft_philo_start_day(t_args *st, t_philo *philo);
void	ft_get_fork(t_args *st);
void	ft_eat(t_args *st, int id, t_philo *start, int i);

// ft_e_s_t_d.c

int		ft_sleep(int time, t_philo *philo);
int		ft_think(int time, t_philo *philo);
