#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>        // printf
# include <stdlib.h>       // malloc, free
# include <string.h>       // memset
# include <unistd.h>       // usleep, write
# include <sys/time.h>     // gettimeofday
# include <pthread.h>      // потоки и мьютексы
# include <stdio.h>

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
	int				eat_count;
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	deat;
	pthread_mutex_t	meal_m;
	pthread_mutex_t	time_t;
	pthread_t		monitor;
	struct timeval	start;
	int				free;
	int				ac;
	t_philo			*philo;
}	t_args;

//ft_free.c
void	ft_free_and_end(t_args *st, int c);
void	ft_free_arr(int **arr);

//ft_create_philo.c
void	*ft_monitor(void *arg);
void	ft_create(t_args *st, t_philo *s_philo, int i);
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
void	ft_print_all(t_args *st, long time, int id, int action);

//ft_philo_start_day.c

void	*my_thread_function(void *arg);
int		ft_get_fork(t_philo *philo, int id);
void	ft_eat(t_args *st, int left, int rigth, int id);
void	ft_sleep(t_args *st, int id);
void	ft_think(t_args *st, int ids);
//time.c

int		get_someone_died(t_args *st);
void	set_someone_died(t_args *st, int id);
void	ft_daid(pthread_mutex_t *l, int id, long time, t_args *st);
long	ft_timestamp(struct timeval *start);
void	ft_time(t_args *st, int id);

///ft_utilc.c
int		ft_c_d(pthread_mutex_t	*d, int check, t_philo *philo);
void	ft_unlock(pthread_mutex_t *l, pthread_mutex_t *r);
void	ft_check_death(t_args *st, int id);
void	ft_update(t_args *st, int id);
void	ft_simple_sleep(int ms, t_args *st);
int		chek_eat_count(t_args *st);

/// ft_utils_tow.c

int		ft_chek_think(t_args *st);
void	ft_iiiii(t_args *st, int left);
void	ft_count(t_args *st, int id, int left, int rigth);
void	ft_monitoring_two(t_args *st, int i);
#endif
/*
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
*/