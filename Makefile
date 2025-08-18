# **************************************************************************** #
#                                  CONFIG                                      #
# **************************************************************************** #

NAME        := fractol
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Iinclude -Iminilibx-linux


SRC_DIR     := src
OBJ_DIR     := obj
MLX_DIR     := minilibx-linux

# Add your source files here
SRC_FILES   := \
				main.c\
				core.c\
				events.c\
				init.c\
				math_utils.c\
				render.c\
				string_utils.c\
				errors.c	

SRC         := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ         := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Libraries (Linux)
MLX_LIB     := -L$(MLX_DIR) -lmlx
MLX_FLAGS   := -lXext -lX11
LIBS        := $(MLX_LIB) $(MLX_FLAGS) -lm

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Compile .c to .o into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

