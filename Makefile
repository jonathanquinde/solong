NAME = solong
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibft/include
LIBFT = libft/libft.a

SRC = src/solong.c src/parse_map.c src/valid_elemcount_border.c src/utils.c src/valid_spawnpoint.c src/bfs.c
OBJ = $(SRC:.c=.o)
HEADERS = include/header.h

all: $(LIBFT) $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@
	@echo "✅ Built $(NAME)"

$(LIBFT):
	@$(MAKE) -C libft

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C libft clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
