# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: morikumo <morikumo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 19:33:02 by mabid             #+#    #+#              #
#    Updated: 2023/01/26 01:05:32 by morikumo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCS = ${wildcard SRCS/*/*.c} SRCS/main.c

OBJS = ${SRCS:.c=.o}

PATH_MLX = ./mlx
CC = gcc

CFLAGS =  -Wall -Werror -Wextra -IINC -g
FLAGS = -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

RM = rm -rf

all: ${NAME} ${CHECK}

.c.o:
	@${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@make -C ${PATH_MLX}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${FLAGS} 

${CHECK}: ${OBJS}
	@make -C ${PATH_MLX}
	@${CC} ${CFLAGS} ${CHECK_OBJS} ${FLAGS} -o ${CHECK}

clean:
	@make clean -C ${PATH_MLX}
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

norminette:
	@norminette ${SRCS} ./INC

wnorme:
	@watch norminette ${SRCS} ./INC

.PHONY: all clean fclean re