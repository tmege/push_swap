NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC			= main.c print_stack.c index.c parser.c error.c sort_small.c operations.c stack_utils.c sort_stack.c
OBJ			= $(SRC:.c=.o)

LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I. -I$(LIBFT_DIR)

all: $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

