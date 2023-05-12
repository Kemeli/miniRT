NAME=miniRT
CC=cc
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I ./includes/

OBJS := tuples/tuples.o
OBJS := $(addprefix sources/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS) main.o
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) $< -c -o $@

tests: $(OBJS)
	@$(CC) $(INCLUDES) -I ./tests/ $(OBJS) ./tests/main.c -o test.out
	@./test.out

.PHONY: tests
