NAME = philo

SRCS = main.c ft_atoi.c ft_args.c ft_init.c ft_time.c \
		ft_dinner.c ft_status.c ft_free.c


CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -pthread

FLAGS_DATARACE = -fsanitize = thread -g

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

data_race:
	@$(CC) $(FLAGS_DATARACE) $(SRCS) -o $(NAME)

clean:
	@rm -rf *.dSYM

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re