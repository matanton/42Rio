# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 11:43:53 by matanton          #+#    #+#              #
#    Updated: 2022/10/12 14:19:34 by matanton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CLIENT = client

SERVER = server

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

LIBFT = libft.a

RM = rm -f

CC = cc

CFLAGS = -Wall -Werror -Wextra

$(NAME): all
	
$(LIBFT):
	make -C ./libft
	@cp ./libft/libft.a ./

$(SERVER): $(LIBFT)
	$(CC) $(CFLAGS) server.c libft.a -o server

$(SERVER_BONUS): $(LIBFT)
	$(CC) $(CFLAGS) server_bonus.c libft.a -o server
	
$(CLIENT_BONUS): $(LIBFT)
	$(CC) $(CFLAGS) client_bonus.c libft.a -o client

$(CLIENT): $(LIBFT)
	$(CC) $(CFLAGS) client.c libft.a -o client

bonus: $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)
	./server

all: $(LIBFT) $(SERVER) $(CLIENT)
	./server

clean:
	${RM} server
	${RM} client
	${RM} ./libft/*.o

fclean: clean
	${RM} libft.a
	${RM} ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re
