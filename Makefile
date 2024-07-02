# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eriviere <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 08:38:34 by eriviere          #+#    #+#              #
#    Updated: 2024/06/25 10:30:51 by eriviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables:
SRC =	./ft_isalpha.c	\
	./ft_isdigit.c	\
	./ft_isalnum.c	\
	./ft_isascii.c	\
	./ft_isprint.c	\
	./ft_toupper.c	\
	./ft_tolower.c	\
	./ft_strlen.c	\
	./ft_strlcpy.c	\
	./ft_strlcat.c	\
	./ft_strchr.c	\
	./ft_strrchr.c	\
	./ft_strncmp.c	\
	./ft_strnstr.c	\
	./ft_atoi.c		\
	./ft_memset.c	\
	./ft_memcpy.c	\
	./ft_memchr.c	\
	./ft_memcmp.c	\
	./ft_strdup.c	\
	./ft_calloc.c	\
	./ft_bzero.c	\
	./ft_memmove.c	\
	./ft_substr.c	\
	./ft_strjoin.c	\
	./ft_strtrim.c	\
	./ft_split.c	\
	./ft_itoa.c		\
	./ft_strmapi.c	\
	./ft_striteri.c	\
	./ft_putchar_fd.c \
	./ft_putstr_fd.c \
	./ft_putendl_fd.c \
	./ft_putnbr_fd.c \

OBJS = ${SRC:.c=.o}

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

LIB = ranlib

RM = rm -f

#Bonus
BONUS_SRC = ./ft_lstnew.c	\
	./ft_lstadd_front.c	\
	./ft_lstsize.c		\
	./ft_lstlast.c		\
	./ft_lstadd_back.c	\
	./ft_lstdelone.c	\
	./ft_lstclear.c		\
	./ft_lstiter.c		\

BONUS_OBJ = ${BONUS_SRC:.c=.o}

#Rules:
all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

bonus: ${BONUS_OBJ}
	${AR} ${NAME} ${BONUS_OBJ}
	${LIB} ${NAME}

clean:
	${RM} ${OBJS} ${BONUS_OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
