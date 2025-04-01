CC = cc
CFLAGS = -Wall -Werror -Wextra -g -Iinclude
NAME = mini_rt

LIBFT_DIR = libft
LDFLAGS = -L$(LIBFT_DIR) -lft -lreadline
LIBFT = $(LIBFT_DIR)/libft.a

MLX42_FLAGS = -lmlx42 -lm -lpthread -ldl -lglfw
SRC_DIR = src
OBJS_DIR = objs


SRC =  	main.c \
		init.c \
		exit_handler.c \
		parser/parser.c \
		parser/parse_utils/parse_color.c\
		parser/parse_utils/parse_vector.c \
		parser/parse_utils/input_checker.c \
		parser/parse_types/parse_ambient.c \
		parser/parse_types/parse_camera.c \
		parser/parse_types/parse_light.c \
		parser/parse_types/parse_sphere.c \
		parser/parse_types/parse_plane.c \
		parser/parse_types/parse_cylinder.c \
		parser/parse_utils/file_utils.c \
# Automatically find the full paths of the source files
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(MLX42_FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to create .o files while preserving the subdirectory structure
$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	@mkdir -p $(dir $@)  # Ensure subdirectories exist
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re