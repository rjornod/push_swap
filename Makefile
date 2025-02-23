NAME = push_swap
CFLAGS = -Wextra -Wall -Werror
SRC = 	sources/push_swap.c \
		sources/functions.c \
		sources/rotate.c \
		sources/validation.c \
		sources/algorithm.c \
		sources/cost_calc.c \
		sources/movement.c \
		sources/helper_funcs2.c \
		sources/helper_funcs.c
OBJS = $(SRC:.c=.o)
INCLUDES = -Ilibft -Ift_printf
LIBFT = libft/libft.a
PRINTF = libft/ft_printf/libftprintf.a
CC = cc

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

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