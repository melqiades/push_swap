# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 21:33:59 by lpesan            #+#    #+#              #
#    Updated: 2024/08/05 11:38:11 by melquiade        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c ft_printf.c put_int.c put_str.c put_int_uns.c put_hex.c put_ptr.c get_next_line.c ft_append.c ft_printf_e.c

SRCS		= ${SRC}

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

AR			= ar rc

RM			= rm -f

LIB			= ranlib

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${LIB} ${NAME}

clean:
			rm -f ${OBJS} ${BONUS_OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

bonus: $(OBJS) $(BONUS_OBJ)
		$(AR) $(NAME) $(OBJS) $(BONUS_OBJ)
		$(LIB) $(NAME)

.PHONY:		all clean fclean re

