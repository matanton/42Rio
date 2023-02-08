# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 15:45:42 by matanton          #+#    #+#              #
#    Updated: 2023/02/06 19:22:26 by matanton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = fdf.c fdf.h fdf_utils.c images_events.c fdf_isometric.c

OBJS = ${SRCS}

NAME = fdf

LIBFT = ./libft/libft.a

AR = ar rcs

RM = rm -f

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

OFLAGS = $(CFLAGS) -L ./minilibx -lm -lmlx -framework OpenGL -framework Appkit

all: ${NAME}
	
$(MLX):
	@make -C ./minilibx

$(LIBFT):
	@make -s -C ./libft
	@cp ./libft/libft.a ./

${NAME}: $(LIBFT) $(MLX)
	${CC} ${OFLAGS} ${OBJS} ${LIBFT} ${MLX}

clean:
	${RM} fdf
	${RM} ./libft/*.o

fclean: clean
	${RM} libft.a
	${RM} ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re

