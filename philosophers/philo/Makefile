SRCS = main.c parse.c philo_utils.c routines.c validation.c

NAME = philo

FLAGS = -Wall -Werror -Wextra -g

CC = cc

RM = rm -rf

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) philo.dSYM

fclean: clean
	$(RM) $(NAME)

re: fclean all
