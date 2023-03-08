SRCS = main.c

RM = rm -f

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread

all: $(NAME)

$(NAME):
	make -pthread $(CFLAGS) $(CC) main.c

clean:
	$(RM) a.out

fclean: clean

re: fclean all

.PHONY: all clean fclean re
