NAME=miniRT
CC=cc
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I ./includes/

OBJS := main.o tuples/tuples.o
OBJS := $(addprefix sources/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) $< -c -o $@

tests:
	@$(CC) $(INCLUDES) -I ./tests/ ./tests/main.c -o test.out
	@./test.out

.PHONY: tests
