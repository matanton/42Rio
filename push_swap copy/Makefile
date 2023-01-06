# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 15:45:42 by matanton          #+#    #+#              #
#    Updated: 2023/01/05 14:48:26 by matanton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = validation.c push_swap.c utils.c utils2.c ft_lstnew.c moves.c operations.c ft_sort.c

OBJS = ${SRCS}

NAME = push_swap

LIBFT = libft.a

AR = ar rcs

RM = rm -f

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}
	
$(LIBFT):
	@make -C ./libft
	@cp ./libft/libft.a ./

${NAME}: $(LIBFT)
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o push_swap 

clean:
	${RM} push_swap
	${RM} ./libft/*.o

fclean: clean
	${RM} libft.a
	${RM} ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re

