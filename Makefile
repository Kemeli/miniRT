NAME			= miniRT
CC				= clang
FLAGS			= -Wall -Werror -Wextra
INCLUDES		= -I ./includes/ -I ./lib/minilibx/ -I ./lib/libft/includes
LIBS			= -L ./lib/minilibx/ -lmlx -lm -lXext -lX11 -lz \
					-L ./lib/libft -lft

SRC				= tuples.c
SRC				+= subtract.c
SRC				+= negative.c
SRC				+= multiply_divide.c
SRC				+= addition.c
SRC				+= magnitude.c
SRC				+= normalization.c
SRC				+= dot.c
SRC				+= cross.c
SRC				+= color.c
SRC				+= multiply_colors.c
SRC				+= matrix.c
SRC				+= comparing_matrix.c
SRC				+= multiply_matrix.c
SRC				+= multiply_matrix_tuple.c
SRC				+= transposing_matrix.c
SRC				+= determinants.c
SRC				+= spotting_submatrices.c
SRC				+= minor.c
SRC				+= cofactor.c
SRC				+= inverse.c
SRC				+= utils.c
SRC				+= translation.c
SRC				+= scaling.c
SRC				+= rotation.c
SRC				+= shearing.c
SRC				+= ray.c
SRC				+= intersect_sphere.c
SRC				+= sphere.c
SRC				+= list_intersect.c
SRC				+= hit.c
SRC				+= transform_ray.c
SRC				+= set_transform.c
SRC				+= normal_at.c
SRC				+= reflect_vector.c
SRC				+= lighting.c
SRC				+= lighting_utils.c
SRC				+= create_world.c

OBJ_DIR			= ./obj
OBJ				= $(SRC:.c=.o)
OBJS			= $(addprefix $(OBJ_DIR)/, $(OBJ))

APP := $(OBJS) $(OBJ_DIR)/main.o

VPATH			= ./sources ./sources/tuples ./sources/tuples/operations
VPATH			+= ./sources/tuples/colors
VPATH			+= ./sources/matrix ./sources/matrix/operations
VPATH			+= ./sources/matrix/inverting_matrices
VPATH			+= ./sources/transformations
VPATH			+= ./sources/ray_tracer
VPATH			+= ./sources/world
VPATH			+= ./sources/objects
VPATH			+= ./lib/libft

.DEFAULT_GOAL	= all

$(OBJ_DIR)/%.o: %.c
			$(CC) $(FLAGS) -g3 $(INCLUDES) $< -c -o $@

obj_dir:
		@mkdir -p $(OBJ_DIR)

all: obj_dir $(NAME)

$(NAME): libs $(OBJS) $(APP)
	$(CC) $(APP) $(FLAGS) $(LIBS) -o $(NAME)

libs:
	make all -sC ./lib/libft/
	make all -sC ./lib/minilibx/

clean_libs:
	make fclean -sC ./lib/libft/
	make clean -sC ./lib/minilibx/

clean: clean_libs
	rm -rf $(APP)
	rm -rf $(OBJS)
	rm -rf $(OBJ_DIR)
	rm -rf test.out

tests: libs obj_dir $(OBJS)
	@$(CC) $(INCLUDES) -I ./tests/ $(OBJS) ./tests/main.c $(LIBS) -g3 -o test.out
	@valgrind -q --leak-check=full ./test.out

test: clean tests

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re obj_dir $(NAME) libs clean_libs test tests
