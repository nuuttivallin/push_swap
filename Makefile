CFILES = get_stack.c stack_utils.c stack_utils_2.c swap.c push.c rotate.c \
		reverse_rotate.c push_swap_utils.c sort_small.c sort.c push_a_cheapest.c \
		push_b_cheapest.c main.c

OFILES = $(CFILES:.c=.o)

LIB = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: $(NAME)

$(NAME): $(OFILES)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) $(LIB)

clean:
	rm -f $(OFILES)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
