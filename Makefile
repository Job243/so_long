# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 09:42:50 by smolines          #+#    #+#              #
#    Updated: 2024/07/16 15:07:19 by jmafueni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

BONUS			= so_long_bonus

CC          	= cc

CFLAGS      	= -Wall -Wextra -Werror -g3

MLX 			= ./mlx-linux/libmlx_Linux.a

MLX_FLAGS		= -Lmlx -lXext -lX11

HEADER			= -I./include

SRCS_PATH		= src/

SRCS_BONUS_PATH	= src_bonus/

OBJS_PATH		= obj/

OBJS_BONUS_PATH	= obj_bonus/

RM 				= rm -rf

SRCS = 			util.c \
				so_long.c \
				create_map.c \
				free_mem.c \
				get_next_line.c \
				get_next_line_utils.c \
				error.c \
				parsing.c \
				parsing_suite.c \
				floodfill.c \
				ft_itoa.c \
				display_map.c \
				ft_putnb.c

SRCS_BONUS =	util_bonus.c \
				so_long_bonus.c \
				create_map_bonus.c \
				free_mem_bonus.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				error_bonus.c \
				parsing_bonus.c \
				parsing_suite_bonus.c \
				floodfill_bonus.c \
				ft_itoa_bonus.c \
				display_map_bonus.c \
				ft_putnb_bonus.c

SRCS_ALL = 		${SRCS_BONUS} ${SRCS}

OBJS = 			$(addprefix ${OBJS_PATH}, ${SRCS:.c=.o})

OBJS_BONUS = 	$(addprefix ${OBJS_BONUS_PATH}, ${SRCS_BONUS:.c=.o})

OBJS_ALL = 		${SRCS_ALL:.c=.o}

all: ${NAME}

bonus: ${BONUS}

$(NAME) : ${MLX} ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${HEADER} ${MLX_FLAGS} ${MLX}

$(BONUS) : ${MLX} ${OBJS_BONUS}
	${CC} ${CFLAGS} -o ${BONUS} ${OBJS_BONUS} ${HEADER} ${MLX_FLAGS} ${MLX}

${MLX} 	:
	make -C ./mlx-linux

${OBJS_PATH}%.o:	${SRCS_PATH}%.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} ${HEADER} -I/usr/include -Imlx_linux -O3 -c $< -o $@

${OBJS_BONUS_PATH}%.o:	${SRCS_BONUS_PATH}%.c
	@mkdir -p obj_bonus
	${CC} ${CFLAGS} ${HEADER} -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf ${OBJS}${OBJS_BONUS}

fclean: clean
