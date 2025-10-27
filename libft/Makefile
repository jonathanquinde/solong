NAME     = libft.a
CC       = cc
CFLAGS   = -Wall -Wextra -Werror -Iinclude

SRC = src/ft_atoi.c src/ft_bzero.c src/ft_calloc.c \
      src/ft_toupper.c src/ft_isalnum.c src/ft_isalpha.c \
      src/ft_isascii.c src/ft_tolower.c src/ft_isdigit.c \
      src/ft_isprint.c src/ft_memchr.c src/ft_memcmp.c \
      src/ft_memcpy.c src/ft_memmove.c src/ft_memset.c \
      src/ft_arrstrclean.c src/ft_putchar_fd.c src/ft_putendl_fd.c \
      src/ft_putnbr_fd.c src/ft_putstr_fd.c src/ft_split.c \
      src/ft_strchr.c src/ft_itoa.c src/ft_substr.c src/ft_strdup.c \
      src/ft_striteri.c src/ft_strjoin.c src/ft_strlcat.c src/ft_strlcpy.c \
      src/ft_strlen.c src/ft_strncmp.c src/ft_strnstr.c src/ft_strrchr.c \
      src/ft_mapi.c src/ft_strtrim.c src/ft_strendswith.c \
      src/ft_strlenuntil.c src/ft_strcontains_ch.c src/ft_strindexof.c \
      src/ft_strcpy.c src/ft_strncpy.c src/ft_strappend.c src/ft_strclean.c \
      src/ft_lstadd_front_bonus.c src/ft_lstnew_bonus.c \
      src/ft_lstadd_back_bonus.c src/ft_lstclear_bonus.c \
      src/ft_lstdelone_bonus.c src/ft_lstiter_bonus.c src/ft_lstlast_bonus.c \
      src/ft_lstmap_bonus.c src/ft_lstsize_bonus.c src/ft_lstnew_s.c \
      src/ft_lstreverse.c src/ft_matrixnew.c src/ft_matrixprint.c \
      src/ft_raw_rreadtext.c src/ft_readtext.c src/ft_rreadlines.c \
      src/ft_readlines.c src/ft_queue.c src/ft_matrixclean.c

OBJ = $(SRC:.c=.o)

# ================================================================

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "✅ Library $(NAME) created successfully!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "🧹 Library object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "🧹 Library $(NAME) removed."

re: fclean all

.PHONY: all clean fclean re
