# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 18:11:51 by lpesan            #+#    #+#              #
#    Updated: 2024/07/26 18:59:41 by melquiade        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIBFT	= ./include/libft

HEADERS	= -I ./include -I ${LIBFT}
LIBS	=  ${LIBFT}/libft.a

SRCS	= $(shell find ./src -iname "*.c")

OBJS	= ${SRCS:.c=.o}

all: libft ${NAME}

libft:
	@${MAKE} -C ${LIBFT}

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS} && printf "Compiling: $(notdir $<)\n"

${NAME}: ${OBJS}
	@${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -f ${OBJS}
	@${MAKE} -C ${LIBFT} clean

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${LIBFT} fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft
