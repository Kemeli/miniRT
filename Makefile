NAME=miniRT
CC=cc
FLAGS=-Wall -Werror -Wextra
INCLUDES=-I ./includes/ -I ./lib/minilibx/ -I ./lib/libft/includes
LIBS= -L ./lib/minilibx/ -lmlx -lm -lXext -lX11 -lz
LIBFT = lib/libft/libft.a

OBJS := tuples/tuples.o tuples/operations/subtract.o tuples/operations/negative.o tuples/operations/multiply_divide.o \
		tuples/operations/addition.o tuples/operations/magnitude.o tuples/operations/normalization.o \
		tuples/operations/dot.o tuples/operations/cross.o tuples/colors/color.o tuples/colors/multiply_colors.o \
		matrix/matrix.o matrix/operations/comparing_matrix.o matrix/operations/multiply_matrix.o \
		matrix/operations/multiply_matrix_tuple.o matrix/operations/transposing_matrix.o matrix/inverting_matrices/determinants.o \
		matrix/inverting_matrices/spotting_submatrices.o matrix/inverting_matrices/minor.o \
		matrix/inverting_matrices/cofactor.o matrix/inverting_matrices/inverse.o utils.o transformations/translation.o \
		transformations/scaling.o transformations/rotation.o transformations/shearing.o ray_tracer/ray.o ray_tracer/sphere_intersection.o \
		objects/sphere.o ray_tracer/list_intersect.o ray_tracer/hit.o \
		ray_tracer/transform_ray.o ray_tracer/set_transform.o \
		ray_tracer/normal_at.o ray_tracer/reflect_vector.o ray_tracer/lighting.o \
		ray_tracer/lighting_utils.o

OBJS := $(addprefix sources/, $(OBJS))

APP := $(OBJS) ./sources/main.o

all: $(NAME)

$(NAME): $(APP)
	$(CC) $(FLAGS) $(APP) $(LIBS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -g3 $(INCLUDES) $< $(LIBS) -c -o $@

$(LIBFT):
	make -sC ./lib/libft/

tests: $(OBJS) $(LIBFT)
	@$(CC) $(INCLUDES) -I ./tests/ $(OBJS) ./tests/main.c $(LIBS) $(LIBFT) -g3 -o test.out
	@valgrind -q --leak-check=full ./test.out

clean:
	rm -rf $(APP)
	rm -rf test.out

test: clean tests

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: tests
