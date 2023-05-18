NAME=miniRT
CC=cc
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I ./includes/
LIBS=-lm

OBJS := tuples/tuples.o tuples/operations/subtract.o tuples/operations/negative.o tuples/operations/multiply_divide.o \
    tuples/operations/addition.o tuples/operations/magnitude.o tuples/operations/normalization.o \
		tuples/operations/dot.o tuples/operations/cross.o

OBJS := $(addprefix sources/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS) ./sources/main.o
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) $< $(LIBS) -c -o $@

tests: $(OBJS)
	@$(CC) $(INCLUDES) -I ./tests/ $(OBJS) ./tests/main.c $(LIBS) -o test.out
	@./test.out

.PHONY: tests
