NAME=miniRT
CC=cc
FLAGS=-Wall -Werror -Wextra
INCLUDES=-I ./includes/ -I ./lib/minilibx/
LIBS= -L ./lib/minilibx -lm -lmlx_Linux -lXext -lX11 -lz

OBJS := tuples/tuples.o tuples/operations/subtract.o tuples/operations/negative.o tuples/operations/multiply_divide.o \
	    tuples/operations/addition.o tuples/operations/magnitude.o tuples/operations/normalization.o \
		tuples/operations/dot.o tuples/operations/cross.o tuples/colors/color.o tuples/colors/multiply_colors.o \
		matrix/matrix.o matrix/operations/comparing_matrix.o matrix/operations/multiply_matrix.o

OBJS := $(addprefix sources/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS) ./sources/main.o
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -g3 $(INCLUDES) $< $(LIBS) -c -o $@

tests: $(OBJS)
	@$(CC) $(INCLUDES) -I ./tests/ $(OBJS) ./tests/main.c $(LIBS) -g3 -o test.out
	@valgrind -q --leak-check=full ./test.out

.PHONY: tests
