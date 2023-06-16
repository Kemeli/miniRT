C_LINKED_LISTS			= $(addprefix linked_list/singly/, ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c)
C_DOUBLY_LINKED_LISTS	= $(addprefix linked_list/doubly/, ft_dlstnew.c ft_dlstadd_front.c ft_dlstadd_begin.c ft_dlstfirst.c ft_dlstlast.c ft_dlstadd_back.c ft_dlstsize.c ft_dlstdelone.c ft_dlstclear.c ft_dlstmap.c ft_dlstiter.c)
C_STACK					= $(addprefix stack/, ft_stkclear.c ft_stkinit.c ft_stkis_empty.c ft_stknew.c ft_stkpeek.c ft_stkpop.c ft_stkpush.c)
C_DATA_STRUCTURES		= $(addprefix data_structures/,$(C_LINKED_LISTS) $(C_DOUBLY_LINKED_LISTS) $(C_STACK))

SOURCE		= 	ft_bzero.c			\
				ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_isprint.c		\
				ft_memcpy.c			\
				ft_strlen.c			\
				ft_memset.c			\
				ft_memmove.c		\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_strchr.c			\
				ft_strncmp.c		\
				ft_memchr.c			\
				ft_strrchr.c		\
				ft_strnstr.c		\
				ft_atoi.c			\
				ft_calloc.c			\
				ft_memcmp.c			\
				ft_strdup.c			\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_itoa.c			\
				ft_strmapi.c		\
				ft_striteri.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_salloc.c			\
				get_next_line.c		\
				$(C_DATA_STRUCTURES)

OBJECTS 	= 	$(addprefix objects/,$(SOURCE:.c=.o))

HEADER		=	libft.h

NAME		=	libft.a

FLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all:			$(NAME)

$(NAME):		$(OBJECTS)
				ar -rcs $@ $(OBJECTS)

objects/%.o : %.c
	@mkdir -p $(dir $@)
	cc -g $(FLAGS) -I ./includes -c $< -o $@

clean:
				$(RM) $(OBJECTS)

fclean: 		clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re
