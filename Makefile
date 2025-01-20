NAME = solong
FLAGS = -Wall -Werror -Wextra
CC = cc
LIBFT= libft/libft.a
SRC = solong.c

all: $(NAME)

$(NAME): solong.c
	$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME) 