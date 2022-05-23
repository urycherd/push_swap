# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 12:02:40 by urycherd          #+#    #+#              #
#    Updated: 2022/02/14 15:16:27 by urycherd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

SRCS = push_swap.c commands_swap_push.c commands_rotate.c commands_reverse_rotate.c \
sort_nums.c sup_funct1.c sup_funct2.c sup_funct3.c this_is_the_way.c ways.c ways2.c

CC = cc

LBFPATH = libft/

LBF = libft.a

FLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJS = ${SRCS:.c=.o}

all: ${LBF} ${NAME}

${LBF}:
	@echo "Making ${LBF}"
	@make -C ${LBFPATH}
	@make bonus -C ${LBFPATH} 

${NAME}: ${OBJS}
	${CC} ${FLAGS} -L ${LBFPATH} -lft ${OBJS} -o ${NAME}

${OBJS}: ${HEADER}

.c.o:
	${CC} ${FLAGS} -c $< -o $@

clean:
	@echo "cleaning..."
	${RM} ${OBJS}
	@make -C ${LBFPATH} clean

fclean:
	@echo "cleaning all..."
	${RM} ${OBJS}
	${RM} ${NAME}
	@make -C ${LBFPATH} fclean

re: fclean all

.PHONY: all clean fclean re

