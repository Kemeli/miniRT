NAME=miniRT
CC=cc
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I ./includes/
LIBS=-lm

OBJS := tuples/tuples.o tuples/operations/subtract.o
OBJS := $(addprefix sources/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS) ./sources/main.o
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) $(LIBS) $< -c -o $@

tests: $(OBJS)
	@$(CC) $(INCLUDES) -I ./tests/ $(LIBS) $(OBJS) ./tests/main.c -o test.out
	@./test.out

.PHONY: tests
