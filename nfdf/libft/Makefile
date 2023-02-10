# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 19:07:02 by matanton          #+#    #+#              #
#    Updated: 2023/02/10 18:01:13 by matanton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_toupper.c ft_tolower.c ft_strncmp.c ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_strlcpy.c ft_calloc.c ft_strdup.c ft_strrchr.c ft_strchr.c ft_strlcat.c ft_substr.c ft_memchr.c ft_strtrim.c ft_memcmp.c ft_strnstr.c ft_strjoin.c ft_split.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_printf.c ft_printfutils.c ft_printfutils2.c ft_printfutils3.c get_next_line.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

AR		= ar rcs

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -g

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: 		$(NAME)

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}
			
fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
