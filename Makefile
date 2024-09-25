# Nom de l'exécutable
NAME = so_long

# Répertoires des fichiers sources et d'en-têtes
SRC_DIR = src
INCLUDE_DIR = include
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
MLX_DIR = minilibx-linux

# Les fichiers source
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/check_map_utils.c $(SRC_DIR)/utils.c \
		$(SRC_DIR)/moves.c $(SRC_DIR)/event.c $(SRC_DIR)/create_map.c \
		$(SRC_DIR)/get_next_line.c $(SRC_DIR)/get_next_line_utils.c \
		$(SRC_DIR)/check_map.c

# Les fichiers objets générés à partir des sources
OBJ = $(SRC:.c=.o)

# Les options du compilateur (-I pour inclure les chemins vers les headers)
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(MLX_DIR)

# Commande du compilateur
CC = gcc

# Règle par défaut : compilera l'exécutable
all: $(NAME)

# Générer l'exécutable en liant les fichiers objets
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -no-pie -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Générer les fichiers objets à partir des fichiers sources
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# Remettre à zéro en nettoyant tout et en recompilant
re: fclean all

# Spécifie que ces cibles ne sont pas des fichiers réels
.PHONY: all clean fclean re


# NAME			= so_long

# BONUS			= so_long_bonus

# CC          	= cc

# CFLAGS      	= -Wall -Wextra -Werror -g3

# MLX 			= ./minilibx-linux/libmlx_Linux.a

# MLX_FLAGS		= -L./minilibx-linux -lmlx_Linux -lXext -lX11

# SRCS_PATH		= src/

# SRCS_BONUS_PATH	= src_bonus/

# OBJS_PATH		= obj/

# # OBJS_BONUS_PATH	= obj_bonus/

# LIBFT = ./libft/libft.a

# RM 				= rm -rf

# SRC = 			utils.c \
# 				create_map.c \
# 				free.c \
# 				get_next_line.c \
# 				get_next_line_utils.c \
# 				check_map_utils.c \
# 				check_map.c \
# 				main.c \


# # SRCS_BONUS =	util_bonus.c \
# # 				so_long_bonus.c \
# # 				create_map_bonus.c \
# # 				free_mem_bonus.c \
# # 				get_next_line_bonus.c \
# # 				get_next_line_utils_bonus.c \
# # 				error_bonus.c \
# # 				parsing_bonus.c \
# # 				parsing_suite_bonus.c \
# # 				floodfill_bonus.c \
# # 				ft_itoa_bonus.c \
# # 				display_map_bonus.c \
# # 				ft_putnb_bonus.c

# SRCS = $(addprefix $(SRCS_PATH), $(SRC))

# # SRCS_ALL = 		$(SRCS_BONUS) $(SRCS)

# OBJ =			$(SRCS:.c=.o)

# OBJS = 			$(addprefix $(OBJS_PATH), $(notdir$(OBJ)))

# # OBJS_BONUS = 	$(addprefix ${OBJS_BONUS_PATH}, ${SRCS_BONUS:.c=.o})

# # OBJS_ALL = 		${SRCS_ALL:.c=.o}

# INCS = -I ./include/ -I ./libft

# all: $(OBJS_PATH) $(NAME)

# # bonus: ${BONUS}

# $(OBJS_PATH):
# 		@mkdir -p $(OBJS_PATH)

# $(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(LIBFT) | $(OBJS_PATH)
# 	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

# $(NAME) : $(OBJS) $(LIBFT)  $(MLX)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(MLX) -o $(NAME)

# $(LIBFT):
# 		make -C libft

# # $(BONUS) : ${MLX} ${OBJS_BONUS}
# # 	${CC} ${CFLAGS} -o ${BONUS} ${OBJS_BONUS} ${HEADER} ${MLX_FLAGS} ${MLX}

# $(MLX) 	:
# 	make -C ./mlx-linux

# # ${OBJS_PATH}%.o:	${SRCS_PATH}%.c
# # 	@mkdir -p $(dir $@)
# # 	${CC} ${CFLAGS} ${HEADER} -I/usr/include -Imlx_linux -O3 -c $< -o $@

# # ${OBJS_BONUS_PATH}%.o:	${SRCS_BONUS_PATH}%.c
# # 	@mkdir -p obj_bonus
# # 	${CC} ${CFLAGS} ${HEADER} -I/usr/include -Imlx_linux -O3 -c $< -o $@

# clean:
# 	$(RM) $(OBJS_PATH)/
# 	make -C libft clean

# fclean: clean
# 		$(RM) $(NAME)/
# 		make -C libft fclean

# re : fclean all
