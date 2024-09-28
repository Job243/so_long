NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
MLX_DIR = minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
MLX_LIB = $(MLX_DIR)/libmlx.a

SRC = $(SRC_DIR)/so_long.c $(SRC_DIR)/check_map_utils.c $(SRC_DIR)/utils.c \
		$(SRC_DIR)/moves.c $(SRC_DIR)/print_image.c $(SRC_DIR)/create_map.c \
		$(SRC_DIR)/get_next_line.c $(SRC_DIR)/get_next_line_utils.c \
		$(SRC_DIR)/check_map.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror -g3 -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(MLX_DIR)

CC = gcc

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c |$(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	rmdir $(OBJ_DIR) 2>/dev/null || true
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
