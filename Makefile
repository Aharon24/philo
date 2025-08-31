NAME    = philo
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRC     = philo.c chesk_number.c ft_atoi.c ft_criate_philo.c ft_free.c \
			ft_create_list.c fork_crate.c ft_philo_start_day.c  ft_e_s_t_d.c
OBJ     = $(SRC:.c=.o)



all:  $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
