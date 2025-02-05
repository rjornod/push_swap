NAME = push_swap
CFLAGS = -Wextra -Wall -Werror
SRC = 	sources/push_swap.c \
		sources/functions.c \
		sources/rotate.c \
		sources/string_input.c
OBJS = $(SRC:.c=.o)
INCLUDES = -Ilibft -Ift_printf
LIBFT = libft/libft.a
PRINTF = libft/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(MLX_LIB_DIR) $(LIBFT) $(PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C libft/ft_printf

clean:
	rm -f $(OBJS)
	make -C libft/ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re