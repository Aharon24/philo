#include <stdio.h>        // printf
#include <stdlib.h>       // malloc, free
#include <string.h>       // memset
#include <unistd.h>       // usleep, write
#include <sys/time.h>     // gettimeofday
#include <pthread.h>      // потоки и мьютексы
#include <stdio.h>

struct	s_args;

typedef struct s_time
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
}	t_time_p;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long			last_meal;
	pthread_t		threads;
	struct s_args	*st;

}	t_philo;

typedef struct s_args
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				someone_died;
	long			time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	time_t;
	pthread_t		monitor;
	t_philo			*philo;
	t_time_p		t_start;
	t_time_p		t_end;
	t_time_p		t_now;
	long			tt;
}	t_args;

//ft_free.c
void	ft_free_and_end(t_args *st);
void	ft_free_arr(int **arr);

//ft_create_philo.c
void	*ft_monitor(void *arg);
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
int		ft_atoi(const char *str);
void	ft_print_fork(int i, t_philo *start, int phi_caunt);

//ft_philo_start_day.c

void	*my_thread_function(void *arg);
int		ft_get_fork(t_philo *philo, int id);
void	ft_eat(t_args *st, int left, int rigth, int id);
void	ft_sleep(t_args *st, int id);
void	ft_think(t_args *st, int id);
//time.c

void	ft_get_my_time(t_time_p *t);
void	ft_time_start(t_args *st);
void	ft_daid(pthread_mutex_t *l, pthread_mutex_t *u,int id);
long	ft_timestamp(t_time_p *start);
/*
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
*/
	// philo->st->time = (philo->st->t_end.tv_sec - philo->st->t_start.tv_sec) * 1000
    //          + (philo->st->t_end.tv_usec - philo->st->t_start.tv_usec) / 1000;