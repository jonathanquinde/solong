NAME = solong
FLAGS = -Wall -Werror -Wextra
CC = cc
HEADERS = include/header.h include/libft.h include/get_next_line.h
LIBFT = libft/libft.a
GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
SRC = src/solong.c src/parse_map.c src/validations.c src/utils.c src/validations2.c src/bfs.c
all: $(NAME)

$(NAME): $(SRC) $(GNL) $(LIBFT) $(HEADERS)
	$(CC) -I include $(FLAGS) $(SRC) $(GNL) $(LIBFT) -o $(NAME) 