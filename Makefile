NAME = life_particules
SRC =	init_particules.c \
		search_in_tree.c \
		simulation.c \
		free.c \
		main.c \
		window.c \
		quadtree.c \
		draw.c \
		set_force.c \

CFLAGS = -Wall -Wextra -Iinclude `sdl2-config --cflags` -fsanitize=address
LDFLAGS = `sdl2-config --libs` -lm
CC = cc
OBJ_DIR = obj
SRC_DIR = src

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -g3 -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -fsanitize=address -g3

clean :
	rm -f -r $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : fclean clean all re
