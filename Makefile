NAME=miniRT
CC=cc
FLAGS=-Wall -Werror -Wextra
INCLUDES=-I ./includes/ -I ./lib/minilibx/ -I ./lib/libft/includes
LIBS= -L ./lib/minilibx -lm -lmlx_Linux -lXext -lX11 -lz
LIBFT = lib/libft/libft.a

OBJS := tuples/tuples.o tuples/operations/subtract.o tuples/operations/negative.o tuples/operations/multiply_divide.o \
		tuples/operations/addition.o tuples/operations/magnitude.o tuples/operations/normalization.o \
		tuples/operations/dot.o tuples/operations/cross.o tuples/colors/color.o tuples/colors/multiply_colors.o \
		matrix/matrix.o matrix/operations/comparing_matrix.o matrix/operations/multiply_matrix.o \
		matrix/operations/multiply_matrix_tuple.o matrix/operations/transposing_matrix.o matrix/inverting_matrices/determinants.o \
		matrix/inverting_matrices/spotting_submatrices.o matrix/inverting_matrices/minor.o \
		matrix/inverting_matrices/cofactor.o matrix/inverting_matrices/inverse.o utils.o transformations/translation.o \
		transformations/scaling.o transformations/rotation.o transformations/shearing.o ray/ray.o ray/intersection.o \
		ray/sphere.o ray/list_intersect.o ray/hit.o

OBJS := $(addprefix sources/, $(OBJS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) ./sources/main.o
	$(CC) $(FLAGS) $(OBJS) $(LIBS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -g3 $(INCLUDES) $< $(LIBS) -c -o $@

$(LIBFT):
	make -sC ./lib/libft/

tests: $(OBJS) $(LIBFT)
	@$(CC) $(INCLUDES) -I ./tests/ $(OBJS) ./tests/main.c $(LIBS) $(LIBFT) -g3 -o test.out
	@valgrind -q --leak-check=full ./test.out

.PHONY: tests
